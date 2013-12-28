class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < n) {
        	if (A[i] == elem) {
        		A[i] = A[n - 1];
        		--n;
        	} else {
        		++i;
        	}
        }
        return n;
    }
};