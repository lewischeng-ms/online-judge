class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = 0; // 指向red区域的右邻居
        int q = n - 1; // 指向blue区域的左邻居
        for (int i = p; i <= q;) {
            switch (A[i]) {
        	case 0:
        		swap(A[p], A[i]); // 加入red区域
        		++p;
        		++i; // 现在i位置上的元素之前已经处理过了，可以继续前进
        		break;
        	case 1:
        		// 留在white区域，什么都不用动，继续前进
                ++i;
        		break;
        	case 2:
        		swap(A[i], A[q]); // 加入blue区域
        		--q; // 这里不能++i，因为交换过来的元素还未被处理过
        		break;
        	}
        }
    }
};