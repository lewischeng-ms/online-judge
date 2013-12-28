class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        for (i = m - 1; i >= 0; --i)
            A[i + n] = A[i];
        i = n;
        
        int j = 0;
        int k = 0;
        while (i < n + m && j < n) {
            if (A[i] <= B[j])
                A[k++] = A[i++];
            else
                A[k++] = B[j++];
        }
        
        while (i < n + m)
            A[k++] = A[i++];
        while (j < n)
            A[k++] = B[j++];
    }
};