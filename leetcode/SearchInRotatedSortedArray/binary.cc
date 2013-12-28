class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = n - 1;
        while (i < j - 1) {
        	int m = (i - j) / 2 + j;
        	if (A[m] == target)
        		return m;
        	if (A[i] == target)
        		return i;
        	if (A[j] == target)
        		return j;
        	if (A[i] < A[m]) {
        		if (target > A[i] && target < A[m]) {
        			j = m - 1;
        		} else {
        			i = m + 1;
        		}
        	} else {
        		if (target > A[m] && target < A[j]) {
        			i = m + 1;
        		} else {
        			j = m - 1;
        		}
        	}
        }
        if (A[i] == target)
        	return i;
        else if (A[j] == target)
        	return j;
        else
        	return -1;
    }
};