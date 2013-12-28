class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // 从倒数第二行开始往前遍历。
        for(int i = triangle.size() - 2 ; i >= 0; --i) 
            // “删除”第i+1行，把第i+1行到第i行相应元素的最小和合并到第i行，
            // 以后就可以不用考虑第i+1行了。
            for(int j = 0; j < triangle[i].size(); ++j)   
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        return triangle[0][0];
    }
};