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
        if (!root) return result;
        deque<TreeNode *> q;
        int level = 0;
        q.push_back(root);
        q.push_back(NULL);
        while (q.size() > 1) {
            vector<int> l;
            while (true) {
        		TreeNode *s = q.front();
        		q.pop_front();
        		if (!s) break;
        		l.push_back(s->val);
        		if (s->left)
        			q.push_back(s->left);
        		if (s->right)
        			q.push_back(s->right);
        	}
        	if (level++ & 1)
        		reverse(l.begin(), l.end());
        	result.push_back(l);
        	q.push_back(NULL);
        }
        return result;
    }
};