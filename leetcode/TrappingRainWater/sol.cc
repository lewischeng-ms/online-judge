class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left(n); // left[i]是第i个节点及之前最大的高度
        int maxHeight = 0;
        for(int i = 0; i < n; i++)
        {
            left[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        vector<int> right(n); // right[i]是第i个节点及之后最大的高度
        maxHeight = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            right[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        int water = 0;
        for(int i = 0; i < n; i++)
        {
        	// 第i个节点上面可以放的水柱体积=最大水高度-节点自身高度。
        	// 而最大水高度取决于两边节点高度最大值之中的较小者（木桶原理）。
            int height = min(left[i], right[i]) - A[i];
            if (height < 0)
                height = 0;
            water += height;
        }
        
        return water;
    }
};