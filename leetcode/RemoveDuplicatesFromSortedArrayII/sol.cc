class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = 0;
        while (i < n) {
            int x = A[i++];
        	A[j++] = x;
        	int c = 1;
        	while (i < n && A[i] == x) {
        		++i;
                ++c;
        		if (c < 3)
        			A[j++] = x;
        	}
        }
        return j;
    }
};