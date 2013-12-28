class Solution {
public:
    bool dfs(int dep, int maxDep, int i, int j, vector<vector<char> > &board, string &word) {
        if (dep >= maxDep)
            return true;
        if (dep == 0) {
            for (i = 0; i < m; ++i)
                for (j = 0; j < n; ++j)
                    if (board[i][j] == word[0]) {
                        canUse[i][j] = false;
                        bool ret = dfs(dep + 1, maxDep, i, j, board, word);
                        canUse[i][j] = true;
                        if (ret) return true;
                    }
        } else {
            // up
            if (i > 0 && canUse[i - 1][j] && board[i - 1][j] == word[dep]) {
                canUse[i - 1][j] = false;
                bool ret = dfs(dep + 1, maxDep, i - 1, j, board, word);
                canUse[i - 1][j] = true;
                if (ret) return true;
            }
            // down
            if (i < m - 1 && canUse[i + 1][j] && board[i + 1][j] == word[dep]) {
                canUse[i + 1][j] = false;
                bool ret = dfs(dep + 1, maxDep, i + 1, j, board, word);
                canUse[i + 1][j] = true;
                if (ret) return true;
            }
            // left
            if (j > 0 && canUse[i][j - 1] && board[i][j - 1] == word[dep]) {
                canUse[i][j - 1] = false;
                bool ret = dfs(dep + 1, maxDep, i, j - 1, board, word);
                canUse[i][j - 1] = true;
                if (ret) return true;
            }
            // right
            if (j < n - 1 && canUse[i][j + 1] && board[i][j + 1] == word[dep]) {
                canUse[i][j + 1] = false;
                bool ret = dfs(dep + 1, maxDep, i, j + 1, board, word);
                canUse[i][j + 1] = true;
                if (ret) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.empty()) return true;
        m = board.size();
        if (m < 1) return false;
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                canUse[i][j] = true;
        return dfs(0, word.size(), -1, -1, board, word);
    }
private:
    bool canUse[1000][1000];
    int m;
    int n;
};