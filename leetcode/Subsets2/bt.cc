class Solution {
private:
    vector<vector<int> > ret;
    bool canUse[100];
public:
    void dfs(int dep, int maxDep, vector<int> &num, vector<int> a, int start)
    {
        ret.push_back(a);
        
        if (dep == maxDep)
            return;
            
        for(int i = start; i < num.size(); i++)
            if (i == 0)
            {
                canUse[i] = false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep + 1, maxDep, num, b, i + 1);
                canUse[i] = true; 
            }
            else
            {
                if (num[i] == num[i-1] && canUse[i-1])
                    continue;
                    
                canUse[i] = false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep + 1, maxDep, num, b, i + 1);
                canUse[i] = true;
            }          
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        vector<int> a;
        dfs(0, S.size(), S, a, 0);
        return ret;
    }
};