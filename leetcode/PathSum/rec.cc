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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return false;
        int subsum = sum - root->val;
        if (!root->left && !root->right && !subsum)
        	return true;
        return hasPathSum(root->left, subsum) ||
        		hasPathSum(root->right, subsum);
    }
};