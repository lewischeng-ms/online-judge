class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s1.size() + s2.size() != s3.size())
            return false;
        b[0][0] = true;
        for (int i = 1; i <= s1.size(); ++i)
            b[i][0] = b[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= s2.size(); ++j)
            b[0][j] = b[0][j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                int k = i + j - 1;
                b[i][j] = b[i - 1][j] && s1[i - 1] == s3[k] ||
                    b[i][j - 1] && s2[j - 1] == s3[k];
            }
        }
        return b[s1.size()][s2.size()];
    }
private:
    bool b[1000][1000];
};