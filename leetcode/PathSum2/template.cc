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
	void dfs(TreeNode *root, int sum) {
		int subsum = sum - root->val;
		if (!root->left && !root->right && !subsum) {
			result.push_back(v);
		} else {
			if (root->left) {
				v.push_back(root->left->val);
				dfs(root->left, subsum);
				v.pop_back();
			}
			if (root->right) {
				v.push_back(root->right->val);
				dfs(root->right, subsum);
				v.pop_back();
			}
		}
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if (!root) return result;
        v.clear();
        v.push_back(root->val);
        dfs(root, sum);
        return result;
    }
private:
	vector<vector<int> > result;
	vector<int> v;
};