class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // (k, i) -> (i, n - 1 - k)
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
        		swap(matrix[j][n - 1 - i], matrix[i][j]);
                swap(matrix[n - 1 - i][n - 1 - j], matrix[i][j]);
                swap(matrix[n - 1 - j][i], matrix[i][j]);
        	}
        }
    }
};