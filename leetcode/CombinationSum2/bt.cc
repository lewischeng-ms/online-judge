class Solution {
public:
    void helper(int target, vector<int> &candidates, int i, vector<vector<int> > &result) {
        if (target == 0) {
            vector<int> t(v);
            sort(t.begin(), t.end());
			if (find(result.begin(), result.end(), t) == result.end())
				result.push_back(t);
		} else if (target > 0) {
			if (i < candidates.size()) {
				v.push_back(candidates[i]);
				helper(target - candidates[i], candidates, i + 1, result);				helper(target - candidates[i], candidates, i + 1, result);
				v.pop_back();
				helper(target, candidates, i + 1, result);
			} else {

			}
		}
	}

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        helper(target, candidates, 0, result);
        return result;
    }
private:
	vector<int> v;
};