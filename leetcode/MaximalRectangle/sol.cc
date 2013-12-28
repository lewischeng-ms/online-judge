// 参考：http://discuss.leetcode.com/questions/260/maximal-rectangle
class Solution {
public:
    // 原理简述：
    // 对于元素a[i][j] == 1，定义其hanging line为：
    //     从a[i][j]出发向上走，走过连续的若干1，直至遇到0或者矩阵边界为止。
    //     定义H[j]为第j列目前的悬线长度
    //     L[j]是距离第j列左边最近的0的位置+1
    //     R[j]是距离第j列右边最近的0的位置
    //     可知在H[j]高度范围内，L[j]到R[j]间的元素全是1，
    //     否则不妨设在第j列左边出现个0，那么L[j]必然比现在要大，与“最近”矛盾。
    //     所以此时矩形的面积很显然就是H[j] * (R[j] - L[j])
    //     往后每添加一行，就有可能会更新L[j]、R[j]和H[j]，
    //     但一定能保证找到最大矩形。
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int n = matrix[0].size();
        vector<int> H(n);
        vector<int> L(n);
        vector<int> R(n, n);

        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int left = 0, right = n;
            // calculate L(i, j) from left to right
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                }
                else {
                    left = j+1;
                    H[j] = 0; L[j] = 0; R[j] = n;
                }
            }
            // calculate R(i, j) from right to left
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                }
                else {
                    right = j;
                }
            }
        }

        return ret;
    }
};