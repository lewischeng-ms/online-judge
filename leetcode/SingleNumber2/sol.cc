class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int single = 0;
        for(int i = 0; i < 32; ++i) {
            unsigned mask = 1 << i;
            int one_count = 0;
            for (int j = 0; j < n; ++j)
                if (A[j] & mask)
                    ++one_count;
            // 若single的第i位为1，则所有数中该位出现1的个数一定是3k+1；
            // 若single的第i位为0，则所有数中该位出现1的个数一定是3k。
            if (one_count % 3 == 1)
                single |= mask;
        }
        return single;
    }
};