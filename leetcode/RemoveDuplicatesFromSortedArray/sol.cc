class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        int m = 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] != A[m - 1]) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};