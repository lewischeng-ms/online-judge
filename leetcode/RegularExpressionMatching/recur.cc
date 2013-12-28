class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        switch (*p) {
            case 0:
            return !*s;
            case '.':
            if (*(p + 1) == '*')
                return *s && isMatch(s + 1, p) || isMatch(s, p + 2);
            else
                return *s && isMatch(s + 1, p + 1);
            default:
            if (*(p + 1) == '*')
                return *s == *p && isMatch(s + 1, p) || isMatch(s, p + 2);
            else
                return *s == *p && isMatch(s + 1, p + 1);
        }
    }
};