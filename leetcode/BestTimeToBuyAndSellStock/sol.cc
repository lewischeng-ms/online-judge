class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = 0;
        vector<int> mins(prices.size());
        for (int i = 0; i < prices.size(); ++i) {
            if (i == 0) {
        		mins[0] = prices[0];
        	} else {
        		mins[i] = min(prices[i], mins[i - 1]);
        	}
        	int d = prices[i] - mins[i];
        	if (d > m) m = d;
        }
        return m;
    }
};