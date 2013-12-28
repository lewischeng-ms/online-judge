class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return true;
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }
            if (!isalnum(s[j])) {
                --j;
                continue;
            }
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] += 32;
            
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};