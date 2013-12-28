class Solution {
public:
    void helper(string &prefix, string s) {
        int c = 0;
        string::iterator i = prefix.begin();
        string::iterator j = s.begin();
        while (i != prefix.end() && j != s.end() && *i++ == *j++)
            ++c;
        prefix.resize(c);
    }
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size() && !prefix.empty(); ++i)
            helper(prefix, strs[i]);
        return prefix;
    }
};