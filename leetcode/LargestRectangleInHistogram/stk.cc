class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        // 第i项j<=i代表：height[k]>=height[i], for all j <= k <= i.
        // 通俗地说，就是矩形从第i项往左最远能扩展到第j项。
        vector<int> leftmost(n);
        // 第i项j>=i代表：height[k]>=height[i], for all i <= k <= j.
        // 即矩形从第i项往右最远能扩展到第j项。
        vector<int> rightmost(n);
        
        stack<int> stk1; stack<int> stk2;
        
        // from left to right to construct 'leftmost'.
        for (int i = 0; i < n; ++i) {
            // 先假设第i项不能向左扩展。
            leftmost[i] = i;
            if (stk1.empty()) {
                // 如果栈为空，直接压入第i项。
                stk1.push(i);
            } else {
                // 如果栈不为空，连续弹出比第i项高的项，这些项都可以被纳入矩形的扩展范围。
                while (!stk1.empty() && height[stk1.top()] >= height[i]) {
                    // 利用第top项向左扩展矩形：
                    // 第top项高度比第i项高，
                    // 它往左能到达的最远地方一定是第i项能达到的地方。
                    leftmost[i] = leftmost[stk1.top()];
                    stk1.pop();
                }
                // 压入第i项，使得第i项以后的项都可以利用该项向左扩展。
                stk1.push(i);
            }
        }
        
        // from right to left to construct 'rightmost'.
        // 意思同上。
        for (int i = n - 1; i >= 0; --i) {
            rightmost[i] = i;
            if (stk2.empty()) {
                stk2.push(i);
            } else {
                while (!stk2.empty() && height[stk2.top()] >= height[i]) {
                    rightmost[i] = rightmost[stk2.top()];
                    stk2.pop();
                }
                stk2.push(i);
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            // 面积 = （第i项向右扩展的最远距离 - 第i项向左扩展的最远距离）* 第i项的高度。
            int area = height[i] * (rightmost[i] - leftmost[i] + 1);
            if (area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
