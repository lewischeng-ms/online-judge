const char *mapping[] = {
    " ", "", "abc",
	"def", "ghi", "jkl",
	"mno", "pqrs", "tuv",
	"wxyz"
};

int len[] = {
	1, 0, 3,
	3, 3, 3,
	3, 4, 3,
	4
};

class Solution {
public:
	string s;

	void helper(string &digits, int index, vector<string> &result){
		if (index >= digits.size()) {
			result.push_back(s);
		} else {
			int d = digits[index] - '0';
			const char *letters = mapping[d];
			for (int i = 0; i < len[d]; ++i) {
				s += letters[i];
				helper(digits, index + 1, result);
				s.resize(s.size() - 1);
			}
		}   
	}

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        helper(digits, 0, result);
        return result;
    }
};