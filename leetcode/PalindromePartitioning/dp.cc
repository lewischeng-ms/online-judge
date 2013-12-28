class Solution {
public:
    void dfs(int dep, int maxDep, const string &s) {
		if (dep >= maxDep) {
			result.push_back(v);
		} else {
			for (int j = dep; j < maxDep; ++j) {
				if (isPalin[dep][j]) {
					v.push_back(s.substr(dep, j - dep + 1));
					dfs(j + 1, maxDep, s);
					v.pop_back();
				}
			}
		}
	}

    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        int n = s.size();
        for (int i = 0; i <= n; ++i) {
        	isPalin[i][i] = true;
        	for (int j = i - 2, k = i; j >= 0 && k < n; --j, ++k)
        		isPalin[j][k] = s[j] == s[k] && isPalin[j + 1][k - 1];
        	if (i == n) break;
        	isPalin[i - 1][i] = s[i - 1] == s[i];
        	for (int j = i - 2, k = i + 1; j >= 0 && k < n; --j, ++k)
        		isPalin[j][k] = s[j] == s[k] && isPalin[j + 1][k - 1];
        }
        dfs(0, n, s);
        return result;
    }
private:
	bool isPalin[1000][1000];
	vector<string> v;
	vector<vector<string>> result;
};