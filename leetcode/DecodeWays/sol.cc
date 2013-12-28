class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if (n < 1) return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int d1 = s[i - 1] - '0';
        	if (d1 >= 1 && d1 <= 9)
        		dp[i] += dp[i - 1];
        	if (i > 1) {
        		int d2 = s[i - 2] - '0';
        		int x = d2 * 10 + d1;
        		if (x >= 10 && x <= 26)
        			dp[i] += dp[i - 2];
        	}
        }
        return dp[n];
    }
};