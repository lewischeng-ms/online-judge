class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 0;
        const char *p = s;
        while (*p) ++p;
        if (p-- == s) return 0; // empty
        while (*p == ' ') --p; // skip the trailing spaces.
        while (p >= s && *p != ' ') {
            --p;
            ++c;
        }
        return c;
    }
};