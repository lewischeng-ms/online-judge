#define MAX_LEN 1000
class Solution {
public:
    static int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
    
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word1.size() < 1)
            return word2.size();
        if (word2.size() < 1)
            return word1.size();
        
        int len1 = word1.size() + 1;
        int len2 = word2.size() + 1;
        
        int dp[MAX_LEN][MAX_LEN];
        
        dp[0][0] = 0;
        for (int i = 1; i < len1; ++i) {
            dp[i][0] = i;
            for (int j = 1; j < len2; ++j) {
                dp[0][j] = j;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
        
        return dp[len1 - 1][len2 - 1];
    }
};