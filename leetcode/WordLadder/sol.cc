class Solution {
public:
    int bfs(const string &start, const string &end, unordered_set<string> &dict) {
        if (start == end)
            return 1;
            
        queue<string> q;
        q.push(start);
        q.push(string());
        int count = 1;
        while (q.size() > 1) {
            string s = q.front();
            q.pop();
            if (s.empty()) {
                ++count;
                q.push(string());
                continue;
            }
            // 尝试更改单词s的每个字母，从a改到z看是否在dict中
            for (int i = 0; i < s.size(); ++i) {
            	string t = s;
            	for (char c = 'a'; c <= 'z'; ++c) {
            		t[i] = c;

            		if (dict.find(t) == dict.end())
            			continue;

            		if (visited.find(t) != visited.end()) continue;
            		visited.insert(t);

            		if (t == end) return count + 1;

            		q.push(t);
            	}
            }
        }
        return 0;
	}

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    	// 是否已访问过
    	visited.clear();
    	
        return bfs(start, end, dict);
    }
private:
	unordered_set<string> visited;
};