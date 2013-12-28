class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = 0;
        for (int i = 1; i < prices.size(); ++i) {
        	int d = prices[i] - prices[i - 1];
        	if (d > 0) p += d;
        }
        return p;
    }
};