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
    bool helper(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int lh, rh;
        if (!helper(root->left, lh)) return false;
        if (!helper(root->right, rh)) return false;
        height = max(lh, rh) + 1;
        return abs(lh - rh) < 2;
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height;
        return helper(root, height);
    }
};