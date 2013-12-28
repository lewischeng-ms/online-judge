class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();
        if (n < 1) return 0;
        if (obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1; // 左上角肯定不会是障碍吧？？
        for (int i = 1; i < m; ++i)
            if (obstacleGrid[i][0])
        		dp[i][0] = 0; // 是障碍，没有任何路径可以到达
        	else
        		dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < n; ++j)
        	if (obstacleGrid[0][j])
        		dp[0][j] = 0;
        	else
        		dp[0][j] = dp[0][j - 1];
        for (int i = 1; i < m; ++i)
        	for (int j = 1; j < n; ++j)
        		if (obstacleGrid[i][j])
        			dp[i][j] = 0;
        		else
        			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1]; // 右下角应该也不会是障碍吧？
    }
};