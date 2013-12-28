class Solution {
public:
    bool isValid(const string &s)
    {
    	int x = atoi(s.c_str());
        if (s.size() == 1)
            return x >= 0 && x <= 9;
        else if (s.size() == 2)
            return x >= 10 && x <= 99;
        else if (s.size() == 3)
            return x >= 100 && x <= 255;
        else
            return false;
    }
    
    void dfs(int dep, string &s, int i)
    {
    	// 回溯算法的一般DFS框架：
    	// 1. 检测深度是否已超出范围，若是则返回一个解；
    	// 2. 否则向更深一层扩展，每次扩展时检测部分解是否合法，不合法则不扩展。
        if (dep > 3)
        {
            if (i == s.size())
            {
                stringstream ss;
                ss << s.substr(0, last[0] + 1) << '.';
            	ss << s.substr(last[0] + 1, last[1] - last[0]) << '.';
            	ss << s.substr(last[1] + 1, last[2] - last[1]) << '.';
            	ss << s.substr(last[2] + 1, last[3] - last[2]);
                result.push_back(ss.str());
            }
            return;
        }
        
        for(int j = i; j < i + 4 && j < s.size(); j++) {
            if (isValid(s.substr(i, j - i + 1)))
            {
                last[dep] = j;
                dfs(dep + 1, s, j + 1);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        dfs(0, s, 0);
        return result;
    }
private:
    int last[4];
    vector<string> result;
};