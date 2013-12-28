class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = n - 1;
        while (i < j - 1) {
            int m = (j - i) / 2 + i;
        	if (A[m] == target)
        		return true;
        	if (A[i] == target)
        		return true;
        	if (A[j] == target)
        		return true;
        	if (A[i] < A[m]) {
        		if (target > A[i] && target < A[m]) {
        			j = m - 1;
        		} else {
        			i = m + 1;
        		}
        	} else if (A[i] == A[m]) {
                // 如果有重复元素存在，就无法确定是在左半边，还是右半边
                // 但可确定的是i和j都不是，所以直接两端缩小范围。
                ++i;
                --j;
            } else {
        		if (target > A[m] && target < A[j]) {
        			i = m + 1;
        		} else {
        			j = m - 1;
        		}
        	}
        }
        if (A[i] == target)
        	return true;
        else if (A[j] == target)
        	return true;
        else
        	return false;
    }
};
