class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // len[s]是以s为end的最小变换长度
        // 最小是由层序遍历所保证的
        unordered_map<string, int> len;
        len[start] = 0;

        pre.clear();

        dict.insert(end);

        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            const string &s = q.front();
            int l = len[s];
            for (int i = 0; i < s.size(); ++i) {
        		string t(s);
        		for (char c = 'a'; c <= 'z'; ++c) {
        			if (c == s[i]) continue; // t == s
        			t[i] = c;
        			if (dict.count(t) > 0) { // t在dict中
        				if (len.count(t) < 1) { // 如果t还没出现过
        					len[t] = l + 1; // 那么len[t]就是当前层数
        					pre[t].push_back(s); // 令s成为t的前驱
        				    if (t != end)
        						q.push(t);
        				} else if (len[t] == l + 1) {
        						// 如果t出现过，但之前的层数和这次一样，
        						// 那么可能是多个不同的解，
        						// 所以也要加入前驱
        						pre[t].push_back(s);
        				}
        			}
        		}
        	}
        	q.pop();
        }

        result.clear();
        v = vector<string>(1, end);
        dfs(start, end);
        return result;
    }

    void dfs(const string &start, const string &end) {
    	vector<string> &l = pre[end];
    	if (start == end) {
    		result.push_back(v);
    		reverse(result.back().begin(), result.back().end());
    	} else {
    		for (int i = 0; i < l.size(); ++i) {
    			v.push_back(l[i]);
    			dfs(start, l[i]);
    			v.pop_back();
    		}
    	}
    }
private:
    vector<string> v;
	vector<vector<string>> result;
	unordered_map<string, vector<string>> pre; // pre[s]就是s在层序遍历中的前趋
};