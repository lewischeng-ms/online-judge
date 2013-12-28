class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int m = matrix.size();
	int n = matrix[0].size();
        bool frZero = false; // first row is zero?
	bool fcZero = false; // first col is zero?
	for (int j = 0; j < n; ++j) {
		if (matrix[0][j] == 0) {
			frZero = true;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (matrix[i][0] == 0) {
			fcZero = true;
			break;
		}
    	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	// set zeroes according to the first row and first col
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}
	if (frZero) {
		for (int j = 0; j < n; ++j)
			matrix[0][j] = 0;
	}
	if (fcZero) {
		for (int i = 0; i < m; ++i)
			matrix[i][0] = 0;
	}
    }
};