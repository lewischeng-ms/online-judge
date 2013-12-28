class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // 为什么n个节点的BST个数是卡塔兰数？
        // 假设算h(n)，
        // 可知：
        //   (1) 若选1当root，（左子树）那么比1小的有0个数，（右子树）比1大的有n-1个数（包括n）
        //   (2) 若选2当root，那么比2小的有1个数，比2大的有n-2个数
        //   ...
        //   (3) 若选n当root，那么比n小的有n-1个数，比n大的有0个数
        // 因此所有n个节点的BST，共有h(0)h(n-1)+h(1)h(n-2)+...+h(n-1)h(0)
        vector<int> h(n + 1, 0);
        h[0] = h[1] = 1;
        for (int i = 2; i <= n; ++i) {
        	int j = 0;
        	int k = i - 1;
        	while (j <= k) {
        		if (j == k) {
        			h[i] += h[j] * h[j];
        		} else {
        			h[i] += 2 * h[j] * h[k];
        		}
        		++j;
        		--k;
        	}
        }
        return h[n];
    }
};