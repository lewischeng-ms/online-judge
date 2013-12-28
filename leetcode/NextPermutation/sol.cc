// 参考std::next_permutation
// 思路：
// 1. 优先换数的右边。如123，肯定优先换2和3，而不是1和2、或1和3。
// 2. 从右往左找第一个相邻递增数对(a,b)。b以后的序列肯定递减，
// 	  在它们中间交换只会导致数减小，如321，随便怎么交换都会减小。
// 3. 找到数对(a,b)以后，只有改变a才能增加数。所以要在后面的递减序列中
//    找到最小的那个比a大的数c，因为递减，所以直接从右往左找到第一个
//    比a大的数即可。
// 4. 交换a和c，虽然此时已经比原数大了，但仍不是最小的那个。
//    b以后的序列仍然有减小的空间，其实只要对它们逆序一下，
//    得到的序列c...a...b就一定是比原序列ab...c...大的最小序列。
//    即ab...c... < c...a...b < cb...a...
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = 0, end = num.size();

        if (begin == end) // 向量为空
            return;

        if (begin + 1 == end) // 只有一个元素，下一排列就是自己
        	return;

        int i = end - 1; // i指向最后一个元素
        while (true) {
        	int j = i; // j是i后面的那个元素
        	--i;
        	if (num[i] < num[j]) { // 从后往前找到的第一对相邻递增数
        		int k = end; // 从后往前找到的第一个比i大的数k
        		while (!(num[i] < num[--k]));
        		swap(num[i], num[k]); // i和k交换
        		reverse(num.begin() + j, num.end()); // j及以后逆序
        		return;
        	}
        	if (i == begin) { // 整个向量单调递增，直接逆序就是下一排列
        		reverse(num.begin(), num.end());
        		return;
        	}
        }
    }
};