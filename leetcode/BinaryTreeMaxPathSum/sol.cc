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
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int x = root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int y = max(x, max(x + l, x + r));
        result = max(result, max(y, l + x + r));
        return y;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        result = INT_MIN;
        dfs(root);
        return result;
    }
private:
    int result;
};