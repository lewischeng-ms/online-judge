#include <bitset>
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> t(9);
        vector<vector<bool> > rows(9, t), cols(9, t), blks(9, t);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
        		int d = board[i][j] - '1';
        		if (rows[i][d]) return false;
        		rows[i][d] = true;
        		if (cols[j][d]) return false;
        		cols[j][d] = true;
        		int k = (i / 3) * 3 + (j / 3);
        		if (blks[k][d]) return false;
        		blks[k][d] = true;
        	}
        }
        return true;
    }
};