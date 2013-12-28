class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if (m < 1)
        	return 0;
        int n = grid[0].size();
        if (n < 1)
        	return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
        	dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j)
        	dp[0][j] = dp[0][j - 1] + grid[0][j];
        // grid[i][j]只能由grid[i - 1][j]以及grid[i][j - 1]到达
        // 所以它的状态只依赖于此两者。
        for (int i = 1; i < m; ++i)
        	for (int j = 1; j < n; ++j)
        		dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        return dp[m - 1][n - 1];
    }
};