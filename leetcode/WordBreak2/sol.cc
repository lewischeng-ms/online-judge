class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        vector<vector<string> > sols(n + 1);
        sols[0].push_back("");
        for (int i = 1; i <= n; ++i) {
            string word;
            for (int j = i; j > 0; --j) {
                word = s[j - 1] + word;
                if (dict.count(word) > 0) {
                    int m = sols[j - 1].size();
                    for (int k = 0; k < m; ++k) {
                        if (i == n)
                            sols[i].push_back(sols[j - 1][k] + word);
                        else
                            sols[i].push_back(sols[j - 1][k] + word + " ");
                    }
                }
            }
        }
        return sols[n];
    }
};