class Solution {
public:
	bool binarySearch(const vector<int> &v, int target) {
		int i = 0;
		int j = v.size() - 1;
		while (i < j - 1) {
			int m = (i - j) / 2 + j;
			if (target == v[m])
				return true;
			else if (target < v[m])
				j = m - 1;
			else
				i = m + 1;
		}
		if (target == v[i] || target == v[j])
			return true;
		else
			return false;
	}

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = matrix.size() - 1;
        while (i < j - 1) {
        	int m = (i - j) / 2 + j;
        	if (target == matrix[m][0])
        		return true;
        	else if (target < matrix[m][0])
        		j = m - 1;
        	else
        		i = m;
        }
        if (target == matrix[j][0])
        	return true;
        else if (target > matrix[j][0])
        	return binarySearch(matrix[j], target);
        else if (target == matrix[i][0])
        	return true;
        else if (target > matrix[i][0])
        	return binarySearch(matrix[i], target);
        else
        	return false;
    }
};