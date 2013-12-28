class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[1000]; // length of longest substring in s[1..k]
        a[1] = 1;
        for (int k = 2; k <= s.size(); ++k) {
            // a[k] = max(a[k - 1], (k - 1) - j + 1)
            // where s[j..k-1] is longest substring that has no duplicate.
            a[k] = a[k - 1];
            
            // Hash to detect character duplication.
            bool t[26];
            int j;
            for (j = 0; j < 26; ++j)
                t[j] = false;
            // Add s[k - 1] 
            t[s[k - 1] - 'a'] = true;
            
            // Found min j so that s[j..k-1] has no duplicate.
            for (j = k - 2; j >= 0; --j) {
                // if s[j] exists, duplicate, s[j+1..k-1] is desired.
                if (t[s[j] - 'a']) break;
                // add s[j].
                t[s[j] - 'a'] = true;
            }
            ++j;
            // If (k - 1) - j + 1 >= a[k - 1], let a[k] = k - j.
            if (k - j >= a[k - 1])
                a[k] = k - j;
        }
        return a[s.size()];
    }
};