class Solution {
public:
    void helper(int target, vector<int> &candidates, int i, vector<vector<int> > &result) {
		if (target == 0) {
			if (find(result.begin(), result.end(), v) == result.end())
				result.push_back(v);
		} else if (target > 0) {
			if (i < candidates.size()) {
				v.push_back(candidates[i]);
				helper(target - candidates[i], candidates, i, result);
				helper(target - candidates[i], candidates, i + 1, result);
				v.pop_back();
				helper(target, candidates, i + 1, result);
			} else {

			}
		}
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        helper(target, candidates, 0, result);
        for (vector<vector<int> >::iterator it = result.begin();
             it != result.end(); ++it)
                 sort(it->begin(), it->end());
        return result;
    }
private:
	vector<int> v;
};