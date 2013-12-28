/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int dep) {
        if (dep > min) return;
        if (root->left) 
            dfs(root->left, dep + 1);
        if (root->right)
            dfs(root->right, dep + 1);
        if (!root->left && !root->right)
            if (dep < min) min = dep;
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        min = INT_MAX;
        dfs(root, 1);
        return min;
    }
private:
    int min;
};