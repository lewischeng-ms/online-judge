class Solution {
public:
    void helper(int n, int i, int &count) {
        if (i >= n) {
            count++;
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
            helper(n, i + 1, count);
            cols[j] = false;
            lu2rb[a] = false;
            lb2ru[b] = false;
        }
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0;
        cols.resize(n, false);
        lu2rb.resize(2 * n - 1, false);
        lb2ru.resize(2 * n - 1, false);
        helper(n, 0, count);
        return count;
    }
    
private:
    vector<bool> cols;
    vector<bool> lu2rb;
    vector<bool> lb2ru;
};
