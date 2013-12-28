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
    TreeNode *cloneAndPlus(TreeNode *root, int base = 0) {
    	if (!root) return NULL;
		TreeNode *newRoot = new TreeNode(root->val + base);
		newRoot->left = cloneAndPlus(root->left, base);
		newRoot->right = cloneAndPlus(root->right, base);
		return newRoot;
	}

	void genTree(int n) {
		if (n == 0) {
			vector<TreeNode *> tv(1);
			tvv.push_back(tv);
		} else if (n == 1) {
			TreeNode *root = new TreeNode(1);
			vector<TreeNode *> tv(1, root);
			tvv.push_back(tv);
		} else {
			vector<TreeNode *> tv;
			for (int r = 1; r <= n; ++r) {
				// 以r为root
				vector<TreeNode *> &ltv = tvv[r - 1];
				vector<TreeNode *> &rtv = tvv[n - r];
				for (int i = 0; i < ltv.size(); ++i) {
					for (int j = 0; j < rtv.size(); ++j) {
						TreeNode *root = new TreeNode(r);
						root->left = cloneAndPlus(ltv[i]);
						root->right = cloneAndPlus(rtv[j], r);
						tv.push_back(root);
					}
				}
			}
			tvv.push_back(tv);
		}
	}

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = tvv.size(); i <= n; ++i)
        	genTree(i);
        return tvv[n];
    }
private:
	vector<vector<TreeNode *> > tvv;
};