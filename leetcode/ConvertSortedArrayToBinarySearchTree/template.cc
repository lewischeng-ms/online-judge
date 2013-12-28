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
	TreeNode *helper(vector<int> &num, int l, int h) {
		if (l > h) return NULL;
		int m = (h - l) / 2 + l;
		TreeNode *root = new TreeNode(num[m]);
		root->left = helper(num, l, m - 1);
		root->right = helper(num, m + 1, h);
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 1)
        	return NULL;
        return helper(num, 0, num.size() - 1);
    }
};