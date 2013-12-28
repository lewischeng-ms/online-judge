// See 4Sum for more beautiful codes.
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end()); // 先排序
        int i = 0;
        while (i < num.size()) { // 对每个num[i]，求twoSum(-num[i])。
            int x = num[i];
            int j = i + 1; // i之前的元素不用考虑，因为如果有的话，之前就已经匹配过了。
            int k = num.size() - 1;
            while (j < k) { // 两边向中间合拢
                int sum = num[j] + num[k];
                if (sum == -x) { // 找对一个triple
                    vector<int> v;
                    v.push_back(x);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    result.push_back(v);
                    do { ++j; } // j向右找到第一个和原来num[j]不相同的数
                    while (num[j] == num[j - 1]);
                    do { --k; } // k向左找到第一个和原来num[k]不相同的数
                    while (num[k] == num[k + 1]);
                } else if (sum < -x) {
                    ++j;
                } else {
                    --k;
                }
            }
            // 与当前num[i]相同的数就不用再试了。
            do { ++i; }
            while (i < num.size() && num[i] == x);
        }
        return result;
    }
};