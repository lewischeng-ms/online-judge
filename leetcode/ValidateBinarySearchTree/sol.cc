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
    bool helper(TreeNode *root, int &max, int &min) {
		if (!root) return true;
		max = min = root->val;
		if (root->left) {
            int lmax, lmin;
			if (!helper(root->left, lmax, lmin))
				return false;
			if (lmax >= root->val)
				return false;
			min = lmin;
		}
		if (root->right) {
            int rmax, rmin;
			if (!helper(root->right, rmax, rmin))
				return false;
			if (rmin <= root->val)
				return false;
			max = rmax;
		}
		return true;
	}

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max, min;
        return helper(root, max, min);
    }
};