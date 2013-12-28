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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        stack<TreeNode *> s;
        if (!root) return result;
        TreeNode *p = root;
        while (p || !s.empty()) {
            // 一路把p的左孩子压栈
        	while (p) {
        		s.push(p);
        		p = p->left;
        	}
            // 从栈里拿个p出来，访问一下val，然后访问他的右孩子
            p = s.top();
            s.pop();
        	result.push_back(p->val);
        	p = p->right;
        }
        return result;
    }
};