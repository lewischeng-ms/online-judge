class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        for (int i = 0; i < numRows; ++i) {
        	vector<int> v;
        	if (i == 0) {
        		v.push_back(1);
        	} else {
        		v.push_back(1);
        		for (int j = 1; j < result[i - 1].size(); ++j)
        			v.push_back(result[i - 1][j - 1] + result[i - 1][j]);
        		v.push_back(1);
        	}
        	result.push_back(v);
        }
        return result;
    }
};