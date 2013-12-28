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
    void inorder(TreeNode *root) {
		if (!root) return;
        inorder(root->left);
		if (last && root->val < last->val) {
			// 第一个异常节点总归是较大的那个
			if (!first)
				first = last;
			// 第二个异常节点总归是较小的那个
            second = root;
		} else {
			// 顺序正常，继续
			last = root;
		}
		inorder(root->right);
	}
    void recoverTree(TreeNode *root) {
        last = NULL;
        first = NULL;
        inorder(root);
        swap(first->val, second->val);
    }
private:
	TreeNode *last;
	TreeNode *first;
	TreeNode *second;
};