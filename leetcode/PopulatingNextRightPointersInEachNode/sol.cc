/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;

        queue<TreeLinkNode *> q;
        q.push(root);

        while (!q.empty()) {
        	int n = q.size();
        	TreeLinkNode *last = 0;
        	for (int i = 0; i < n; ++i) {
        		TreeLinkNode *x = q.front();
        		q.pop();
        		if (last)
        			last->next = x;
        		last = x;
        		if (x->left)
        			q.push(x->left);
        		if (x->right)
        			q.push(x->right);
        	}
        }
    }
};