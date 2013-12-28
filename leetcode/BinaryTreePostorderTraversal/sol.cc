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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        stack<TreeNode *> s;
        if (root)
        	s.push(root);
        while (!s.empty()) {
        	TreeNode *p = s.top();
        	s.pop();
        	result.push_back(p->val);
        	if (p->left)
        		s.push(p->left);
        	if (p->right)
        		s.push(p->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};