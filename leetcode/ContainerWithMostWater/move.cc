class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // 核心思想：[l,r]区间收缩，每次丢掉l和r中短的那根。
        // 不妨设短的那根是l，l和任意a属于(l,r)组成的矩形面积x
        // 都不可能超过l和r组成的矩形面积y。
        // 因为无非就是a比r长，但是矩形的高取决于短的那条边，
        // a>r>l，也就是高仍然是l，而宽反而缩短了a-l<r-l，
        // 因此矩形面积反而减小了。
        // 这就是说扔掉短的那根只会扔掉那些面积比y小的矩形，
        // 仍然可以保证最优解的产生。
        int l = 0;
        int r = height.size() - 1;
        int max = 0;
        while (l < r) {
            int s = (r - l) * min(height[r], height[l]);
            if (s > max) max = s;
            if (height[r] > height[l])
                l++;
            else
                r--;
        }
        return max;
    }
};