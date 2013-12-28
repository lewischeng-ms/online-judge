class Solution {
public:
    void helper(int n, int i, vector<vector<string> > &sols) {
        if (i >= n) {
            sols.push_back(sol);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (cols[j]) continue;
            int a = i + j;
            if (lu2rb[a]) continue;
            int b = j - i + n - 1;
            if (lb2ru[b]) continue;
            cols[j] = true;
            lu2rb[a] = true;
            lb2ru[b] = true;
            sol[i][j] = 'Q';
            helper(n, i + 1, sols);
            sol[i][j] = '.';
            cols[j] = false;
            lu2rb[a] = false;
            lb2ru[b] = false;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > sols;
        string t(n, '.');
        sol.resize(n);
        // The STL from leetcode has a bug:
        // You can't use sol.resize(n, t), which
        // will result in a weired error.
        for (int j = 0; j < n; ++j)
            sol[j] = t;
        cols.resize(n, false);
        lu2rb.resize(2 * n - 1, false);
        lb2ru.resize(2 * n - 1, false);
        helper(n, 0, sols);
        return sols;
    }
private:
    vector<bool> cols;
    vector<bool> lu2rb;
    vector<bool> lb2ru;
    vector<string> sol;
};
