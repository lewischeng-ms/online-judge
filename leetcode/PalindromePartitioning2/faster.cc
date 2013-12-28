int p[2000][2000];
class Solution {
public:
    inline void set(string &s, int j, int k, int n) {
        for (; j >=0 && k < n; --j, ++k) {
        if (s[j] != s[k]) {
                    p[j][k] = -1;
                } else {
                    p[j][k] = p[j + 1][k - 1];
                }
        }
    }
    inline void set1(string &s, int j, int k, int n) {
        for (; j >=0 && k < n; --j, ++k)
            p[j][k] = -1;
    }
    int minCut(string s) {
        int n = s.size();
        
        for (int i = 0; i < n - 1; ++i) {
            p[i][i] = 1;
            set(s, i - 1, i + 1, n);
            if (s[i] == s[i + 1]) {
                p[i][i + 1] = 1;
                set(s, i - 1, i + 2, n);
            } else {
                p[i][i + 1] = -1;
                set1(s, i - 1, i + 2, n);
            }
        }
    

        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[2000];
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            int min = dp[i - 1] + 1;
            int t;
            for (int j = 0; j < i - 1; ++j) {
                if (p[j][i - 1] == 1) {
                    t = dp[j];
                    if (j > 0) t++;
                    if (t < min) min = t;
                }
            }
            dp[i] = min;
        }
        return dp[n];
    }
};
