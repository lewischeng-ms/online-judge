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
    bool helper(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (!p && !q)
		return true;
	else if (!p && q)
		return false;
	else if (p && !q)
		return false;
	if (p->val != q->val)
		return false;
	return helper(p->left, q->right) && helper(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (!root) return true;
        return helper(root->left, root->right);
    }
};