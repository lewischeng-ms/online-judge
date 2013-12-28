class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (*s == ' ')
            ++s;
        
        if (!*s)
            return false;
        
        if (*s == '+' || *s == '-')
            ++s;
        
        if (!*s)
            return false;
        
        int icnt = 0;
        while (*s >= '0' && *s <= '9') {
            ++s;
            ++icnt;
        }
        
        if (!*s)
            return true;
        
        int dcnt = 0;
        if (*s == '.') {
            ++s;
            while (*s >= '0' && *s <= '9') {
                ++s;
                ++dcnt;
            }
            if (icnt < 1 && dcnt < 1)
                return false;
            if (!*s) {
                if (icnt > 0 || dcnt > 0)
                    return true;
                else
                    return false;
            }
        }
        
        int ecnt = 0;
        if (*s == 'e') {
            if (icnt < 1 && dcnt < 1)
                return false;
            
            ++s;
            if (*s == '+' || *s == '-')
                ++s;
            while (*s >= '0' && *s <= '9') {
                ++s;
                ++ecnt;
            }
            if (ecnt < 1)
                return false;
        }
        
        while (*s == ' ')
            ++s;
        
        if (!*s)
            return true;
        else
            return false;
    }
};