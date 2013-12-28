class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        vector<int> l(prices.size());
        vector<int> r(prices.size());
        vector<int> d1(prices.size());
        vector<int> d2(prices.size());
        int m = 0;
        for (int i = 0, j = prices.size() - 1; i < prices.size(); ++i, --j) {
            if (i == 0) {
                l[0] = prices[0];
                d1[0] = 0;
            } else {
                l[i] = min(l[i - 1], prices[i]);
                d1[i] = max(d1[i - 1], prices[i] - l[i]);
            }
            
            if (j == prices.size() - 1) {
                r[j] = prices[j];
                d2[j] = 0;
            } else {
                r[j] = max(r[j + 1], prices[j]);
                d2[j] = max(d2[j + 1], r[j] - prices[j]);
            }
            
        }
        for (int i = 0; i < prices.size(); ++i) {
            int d = d1[i] + d2[i];
            if (d > m) m = d;
        }
        return m;
    }
};