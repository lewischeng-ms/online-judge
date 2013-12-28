class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[1000]; // length of longest palindrome in s[1..k]
        int b[1000]; // begin of longest palindrome in s[1..k]
        a[1] = 1;
        b[1] = 0;
        for (int k = 2; k <= s.size(); ++k) {
            a[k] = a[k - 1];
            b[k] = b[k - 1];
            
            int j;
            for (j = 0; j <= k - 1; ++j)
                if (isPalindrome(s, j, k - 1))
                    break;
            if (k - j >= a[k]) {
                a[k] = k - j;
                b[k] = j;
            }
        }
        
        return s.substr(b[s.size()], a[s.size()]);
    }
};
