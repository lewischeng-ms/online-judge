class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
        	string single = s.substr(i - 1, 1);
        	if (dp[i - 1] && dict.count(single) > 0) {
        		dp[i] = true;
        	} else {
        		for (int j = i - 1; j > 0; --j) {
        			string word = s.substr(j - 1, i - j + 1);
        			if (dp[j - 1] && dict.count(word) > 0) {
        				dp[i] = true;
        				break;
        			}
        		}
        	}
        }
        return dp[n];
    }
};