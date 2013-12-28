class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i >= m)
            return;

        if (j < 0 || j >= n)
            return;
        
    	if (board[i][j] == 'O') {
			board[i][j] = 0;
			dfs(i + 1, j, board);
			dfs(i - 1, j, board);
			dfs(i, j - 1, board);
			dfs(i, j + 1, board);
		}
	}

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // 核心思想：灌水，被水淹了就改成\0
        // 结束时：把'0'改成'X'（因为都是没被淹到的）
        // 把\0都改成'0'（都是不能改成'X'的）
        m = board.size();
        if (m < 1) return;
        n = board[0].size();
        if (n < 1) return;

        for (int j = 0; j < n; ++j) {
        	dfs(0, j, board);
        	if (m - 1 != 0)
            	dfs(m - 1, j, board);
        }
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, board);
        	if (n - 1 != 0)
            	dfs(i, n - 1, board);
        }

        for (int i = 0; i < m; ++i)
        	for (int j = 0; j < n; ++j)
        		if (board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if (!board[i][j])
        			board[i][j] = 'O';
    }
private:
	int m, n;
};