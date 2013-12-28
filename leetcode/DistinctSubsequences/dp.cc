class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size();
        int n = T.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = 1;
        for (int j = 1; j <= n; ++j)
        	dp[0][j] = 0;
        for (int i = 1; i <= m; ++i) {
        	for (int j = 1; j <= n; ++j) {
                if (S[i - 1] != T[j - 1]) {
                	// 若不相等，那么T[j - 1]只能放弃S[i - 1]，
                	// 转而去匹配S[i - 1]前面的字符。
                    dp[i][j] = dp[i - 1][j];
                } else {
                	// 若相等，那么T[j - 1]既可以选择匹配掉S[i - 1]，
                	// 也可以选择放弃S[i - 1]，匹配它之前的字符。
                	// 不同的匹配方法数量就是两者之和。
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
        	}
        }
        return dp[m][n];
    }
};