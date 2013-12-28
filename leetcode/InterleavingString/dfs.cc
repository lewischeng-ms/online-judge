class Solution {
public:
    bool dfs(int dep, int maxDep, int i, int j, string &s1, string &s2, string &s3) {
        if (dep >= maxDep)
            return i == s1.size() && j == s2.size();
        
        bool result = false;
        if (i < s1.size() && s1[i] == s3[dep]) {
            result = dfs(dep + 1, maxDep, i + 1, j, s1, s2, s3);
        }
        if (!result && j < s2.size() && s2[j] == s3[dep]) {
            result = dfs(dep + 1, maxDep, i, j + 1, s1, s2, s3);
        }
        return result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s1.size() + s2.size() != s3.size())
            return false;
        return dfs(0, s3.size(), 0, 0, s1, s2, s3);
    }
};