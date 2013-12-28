class Solution {
public:
	string s;
	stack<char> stk;

	void helper(int i, int j, int n, vector<string> &result) {
		if (i == n && j == n) {
			result.push_back(s);
		} else {
			if (i < n) {
				stk.push('(');
				s += '(';
				helper(i + 1, j, n, result);
				stk.pop();
				s.resize(s.size() - 1);
			}
			if (j < n) {
				if (stk.empty())
					return;
				stk.pop();
				s += ')';
				helper(i, j + 1, n, result);
				stk.push('(');
				s.resize(s.size() - 1);
			}
		}
	}

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
      	helper(0, 0, n, result);
        return result;
    }
};