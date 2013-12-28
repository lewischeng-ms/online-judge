class Solution {
public:
    static int findIth(int i, int A[], int m, int B[], int n) {
        if (m < 1) return B[i - 1];
        if (n < 1) return A[i - 1];
        int midA = m >> 1;
        int midB = n >> 1;
        if (A[midA] <= B[midB]) { swap(A, B); swap(m, n); swap(midA, midB); }
        int j = midA + midB + 2;
        if (i < j) return findIth(i, B, n, A, midA);
        else return findIth(i - midB - 1, B + midB + 1, n - midB - 1, A, m);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = m + n;
        int r = findIth(s / 2 + 1, A, m, B, n);
        if (s % 2)
            return r;
        int l = findIth(s / 2, A, m, B, n);
        return (l + r) / 2.0;
    }
};