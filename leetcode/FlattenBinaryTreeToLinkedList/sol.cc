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
    void helper(TreeNode *root) {
		if (!root) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = 0;
        root->right = 0;
        last->right = root;
        last = root;
		helper(left);
		helper(right);
	}

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode head(0);
        last = &head;
        helper(root);
    }
private:
	TreeNode *last;
};