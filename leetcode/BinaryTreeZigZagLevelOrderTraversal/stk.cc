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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> level;
        bool l2r = true;
        stack<TreeNode *> current, next;
        current.push(root);
        while (!current.empty()) {
            TreeNode *node = current.top();
            current.pop();
            if (node) {
                level.push_back(node->val);
                if (l2r) {
                    next.push(node->left);
                    next.push(node->right);
                } else {
                    next.push(node->right);
                    next.push(node->left);
                }
            }
            if (current.empty()) {
                swap(current, next);
                if (!level.empty())
                    result.push_back(level);
                l2r = !l2r;
                level.clear();
            }
        }
        return result;
    }
};