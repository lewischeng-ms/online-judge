class Solution {
public:
	bool DFS(int dep, int max_dep,
		const string &s,
		unordered_set<string> &dict) {
		if (dep == max_dep)
			return true;
		for (int i = dep; i < max_dep; ++i) {
			string word = s.substr(dep, i - dep + 1);
			if (dict.count(word) > 0)
				if (DFS(dep + 1, max_dep, s, dict))
					return true;
		}
		return false;
	}

    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return DFS(0, s.size(), s, dict);
    }
};