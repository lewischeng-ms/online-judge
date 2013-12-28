class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
        	for (int j = rowIndex - 1; j > 0; --j)
        		result[j] += result[j - 1];
        	result[rowIndex] = 1;
        }
        return result;
    }
};