class Solution {
public:
	Solution() : empty(9, vector<bool>(9)) {}

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init(board);
        try {
        	helper(board, 0, 0);
        } catch(bool) {

        }
    }
private:
	void init(vector<vector<char> > &board) {
		rows = empty;
		cols = empty;
		blks = empty;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int d = board[i][j] - '1';
					rows[i][d] = true; // row i digit d present.
					cols[j][d] = true; // col j digit d present.
					int k = getBlockId(i, j);
					blks[k][d] = true; // blk k digit d present.
				}
			}
		}
	}

	void helper(vector<vector<char> > &board, int i, int j) {
		if (i > 8) // 已经求出一个解，直接扔个异常，快速退栈
			throw true;

		if (board[i][j] != '.') {
			next(board, i, j);
			return;
		}

		int k = getBlockId(i, j);
		for (int d = 0; d < 9; ++d) {
			if (isValid(d, i, j, k)) {
				rows[i][d] = true;
				cols[j][d] = true;
				blks[k][d] = true;
				board[i][j] = '1' + d;
				next(board, i, j);
				// 回溯
				rows[i][d] = false;
				cols[j][d] = false;
				blks[k][d] = false;
			}
		}
		// 回溯
		board[i][j] = '.';
	}

	int getBlockId(int i, int j) {
		return (i / 3) * 3 + j / 3;
	}

	void next(vector<vector<char> > &board, int i, int j) {
		if (j < 8)
			helper(board, i, j + 1);
		else
			helper(board, i + 1, 0);
	}

	bool isValid(int d, int i, int j, int k) {
		return !rows[i][d] && !cols[j][d] && !blks[k][d];
	}

	vector<vector<bool> > empty;
	vector<vector<bool> > rows;
	vector<vector<bool> > cols;
	vector<vector<bool> > blks;
};