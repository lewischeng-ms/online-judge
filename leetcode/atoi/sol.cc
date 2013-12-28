class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0;
        int s = 1;
        while (*str == ' ')
            ++str;
        if (*str == '+' || *str == '-') {
            if (*str == '-') s = -1;
            ++str;
        }
        while (isdigit(*str)) {
            int d = *str - '0';
            int b = r;
            r = r * 10 + d;
            if (r < 0 || r / 10 < b)
                return s > 0 ? INT_MAX : INT_MIN;
            ++str;
        }
        return r * s;
    }
};
