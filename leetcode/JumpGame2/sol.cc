class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) return 0;
        
        // 基本思想：步步为营
        // “此山望着那山高”
        int max = 0; // 当前最远距离
        int newMax = 0; // 在max范围内跳出去所能到达的最大距离
        int step = 0; // 已跳跃步数
        for (int i = 0; i < n - 1; ++i) {
            int k = i + A[i];
            if (k > newMax) newMax = k;
            if (i >= max) { // max范围已经遍历完，开跳
            	// 这一轮没跳，说明再也没法跳了。
                if (max == newMax)
                	return -1;
                ++step;
                max = newMax;
            }
            if (max >= n - 1) return step;
        }
        
        return -1;
    }
};