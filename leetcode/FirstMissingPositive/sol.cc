class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < n && A[i] <= 0)
            A[i++] = 0;
        if (i == n) return 1; // 无正数
        int minPositive = A[i++];
        while (i < n) {
        	if (A[i] <= 0 || A[i] == minPositive) {
        		A[i] = 0;
        	} else if (A[i] < minPositive) {
        		minPositive = A[i];
        	}
        	++i;
        }
        // 若最小正数>1，那缺的一定是1
        if (minPositive > 1)
            return 1;
        // 此时最小正数必为1
        for (i = 0; i < n; ++i) {
        	// 0代表不用考虑的数（如0或负数或与minPositive相同的数）
        	// -1代表数i+min是A的元素。
        	if (A[i] < 1) continue;
        	// 记录下x=A[i]，然后清零，表示数i+min尚未出现
        	int x = A[i];
            A[i] = 0;
            // 因为把A[i]的位置占了用于记录数i+min，所以要把x=原先的A[i]
            // 也处理一下。
        	while (x > 0) {
        		// x在数组中的位置。
	        	int j = x - minPositive;
	        	if (j >= n) break; // 超出数组范围不用处理
	        	// 占了A[j]的坑，还要处理x=原先的A[j]
	        	x = A[j];
	        	// 标记数j+min已经出现
	        	A[j] = -1;
	        }
        }
        // 查找第一个0
        for (i = 0; i < n; ++i)
        	if (A[i] == 0)
        		break;
        return minPositive + i;
    }
};