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
    bool findX(vector<int> &src, int l, int h, int x) {
    	vector<int>::iterator end = src.begin() + h + 1;
		return find(src.begin() + l, end, x) != end;
	}

	TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int lp, int hp, int li, int hi) {
		if (lp > hp || li > hi) return NULL;

		// 先序的第一个元素是根
		TreeNode *root = new TreeNode(preorder[lp]);

		// 根在中序中的位置ri, 所以：
		// 左子树在inorder中的位置[li, ri - 1]
		// 右子树在inorder中的位置[ri + 1, hi]
		int ri;
		for (ri = li; ri <= hi; ++ri)
			if (inorder[ri] == root->val)
				break;
		if (ri > hi) return NULL; // Error!

		// 在先序中找到右子树的右边界rrp
		int rrp = hp;
		// 在先序中找到右子树的左边界rlp
		int rlp = lp + 1;
		while (rlp <= rrp) {
			if (findX(inorder, ri + 1, hi, preorder[rlp]))
				break;
			++rlp;
		}
		if (rlp > rrp)
			root->right = NULL;
		else
			root->right = helper(preorder, inorder, rlp, rrp, ri + 1, hi);

		// 在先序中找到左子树的左边界llp
		int llp = lp + 1;
		// 在先序中找到左子树的右边界lrp
		int lrp = rlp - 1;
		if (llp > lrp)
			root->left = NULL;
		else
			root->left = helper(preorder, inorder, llp, lrp, li, ri - 1);

		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() < 1 || inorder.size() < 1)
        	return NULL;
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};