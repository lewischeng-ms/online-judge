
int p[2000][2000];
class Solution {
public:
    int pf(string &s, int i, int j) {
        if (i > j)
            return -1;
        
        if (i == j) return 1;
        
        if (s[i] != s[j]) return -1;
        
        if (i == j - 1) return 1;
        
        p[i + 1][j - 1] = pf(s, i + 1, j - 1);
        return p[i + 1][j - 1];
    }

    int minCut(string s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                p[i][j] = 0;
            }
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (p[i][j] == 0)
                p[i][j] = pf(s, i, j);
            }
        }

        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size() + 1;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= s.size(); ++i) {
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
        return dp[s.size()];
    }
};

