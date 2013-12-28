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
    void preOrder(TreeNode *root, int s) {
		s = s * 10 + root->val;
        if (!root->left && !root->right) {
            sum += s;
            return;
        }
        if (root->left)
		preOrder(root->left, s);
        if (root->right)
		preOrder(root->right, s);
	}
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        sum = 0;
        preOrder(root, 0);
        return sum;
    }
private:
	int sum;
};