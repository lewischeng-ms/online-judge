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

	TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int li, int hi, int lp, int hp) {
		if (li > hi || lp > hp) return NULL;

		// 后序的最后一个元素是根
		TreeNode *root = new TreeNode(postorder[hp]);

		// 根在中序中的位置ri，所以：
		// 左子树在inorder中的位置[li, ri - 1]
		// 右子树在inorder中的位置[ri + 1, hi]
		int ri;
		for (ri = li; ri <= hi; ++ri)
			if (inorder[ri] == root->val)
				break;
		if (ri > hi) return NULL; // Error!

		// 在后序中找到左子树的左边界llp
		int llp = lp;//findBound(inorder, li, ri - 1, postorder, lp, hp, 0);
		// 在后序中找到左子树的右边界lrp
		int lrp = hp - 1;
		while (lrp >= llp) {
			if (findX(inorder, li, ri - 1, postorder[lrp]))
				break;
			--lrp;
		}
		if (lrp < llp)
			root->left = NULL;
		else
			root->left = helper(inorder, postorder, li, ri - 1, llp, lrp);

		// 在后序中找到右子树的右边界rrp
		int rrp = hp - 1;
		// 在后序中找到右子树的左边界rlp
		int rlp = lrp + 1;
		if (rrp < rlp)
			root->right = NULL;
		else
			root->right = helper(inorder, postorder, ri + 1, hi, rlp, rrp);
		
		return root;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() < 1 || postorder.size() < 1)
        	return NULL;
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};