class Solution {
public:
    bool checkLeft(int A[], int i, int target) {
		return A[i] == target && A[i - 1] != target;
	}

	bool checkRight(int A[], int i, int target) {
		return A[i] == target && A[i + 1] != target;
	}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2, -1);

        bool decided = false;
        int l;
        if (A[0] == target) {
        	l = 0;
        } else {
        	int i = 1;
        	int j = n - 1;
        	while (i < j - 1) {
        		int m = (i - j) / 2 + j;
        		if (checkLeft(A, m, target)) {
        			decided = true;
        			l = m;
        			break;
        		}
        		if (A[m] < target)
        			i = m + 1;
        		else
        			j = m - 1;
        	}
        	if (!decided) {
        		if (checkLeft(A, i, target))
        			l = i;
        		else if (checkLeft(A, j, target))
        			l = j;
        		else
        			return result;
        	}
        }

        int r;
        if (A[n - 1] == target) {
        	r = n - 1;
        } else {
        	decided = false;
        	int i = 0;
        	int j = n - 2;
        	while (i < j - 1) {
        		int m = (i - j) / 2 + j;
        		if (checkRight(A, m, target)) {
        			decided = true;
        			r = m;
        			break;
        		}
        		if (A[m] > target)
        			j = m - 1;
        		else
        			i = m + 1;
        	}
        	if (!decided) {
        		if (checkRight(A, i, target))
        			r = i;
        		else if (checkRight(A, j, target))
        			r = j;
        		else
        			return result;
        	}
        }
        
        result[0] = l;
        result[1] = r;
        return result;
    }
};