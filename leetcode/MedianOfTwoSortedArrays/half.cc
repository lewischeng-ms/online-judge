class Solution {
public:
    static int findIth(int i, int A[], int m, int B[], int n) {
        if (m < 1)
            return B[i - 1];
        if (n < 1)
            return A[i - 1];
        int midA = m / 2;
        int midB = n / 2;
        int *greater, *less; // the array with the greater (less) middle element
        int gtLen, lsLen; // the length of the greater (less) array
        int gtMid, lsMid; // the position of the middle element in the greater (less) array.
        if (A[midA] > B[midB]) {
            greater = A;
            less = B;
            gtLen = m;
            lsLen = n;
            gtMid = midA;
            lsMid = midB;
        } else {
            greater = B;
            gtLen = n;
            less = A;
            lsLen = m;
            gtMid = midB;
            lsMid = midA;
        }
        int j = midA + midB + 2; // index of the greater middle element.
        if (i < j)
            // the greater middle element x ranks at least postion j.
            // If i < j, then any element >= x, namely in 'greater' array
            // whose position > gtMid must not be the ones we are looking for.
            // So discard elements in 'greater' array whose position > gtMid.
            return findIth(i, less, lsLen, greater, gtMid);
        else
            // the less middle element y ranks at most x's position.
            // If i >= j, then the position of any element <= y < x
            // must be < j, thus < i.
            // So these elements must not be the ones we are looking for.
            // So discard elements in 'less' array whose position <= lsMid.
            // There are totally lsMid + 1 elements to be discarded.
            // Notice that: elements in 'greater' array cannot be discarded
            // because x is just at least j, so we are not sure that the
            // position of elements < x in that array is < i.
            return findIth(i - lsMid - 1, less + lsMid + 1, lsLen - lsMid - 1, greater, gtLen);
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