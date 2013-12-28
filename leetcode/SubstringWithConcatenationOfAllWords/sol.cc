class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = L.size(); // 多少个word
        map<string, int> c;
        for (int i = 0; i < n; ++i)
            c[L[i]]++; // 统计每个word出现频率

        int m = S.size(); // S的长度
        int k = L[0].size(); // 每个word的长度
        int subLen = n * k; // 一个substring的长度
        vector<int> result;
        for (int i = 0; i + subLen <= m; ++i) {
        	bool valid = true; // 是否出现过invalid word？
            int wc = 0; // 已匹配的word数
        	map<string, int> _c; // 本次匹配中每个word出现频率
        	 // 结束条件：已经匹配了wc个单词或者剩余字符数不足k个
        	for (int j = i; wc < n && j + k <= m; j += k) {
        		string s = S.substr(j, k);
                int a = c[s]; // 获得s在L中的出现频率
                if (a == 0) { // s在L中没有出现过，说明s invalid
                    valid = false;
                    // 并且这次匹配也不用进行下去了
                    break;
                }
                // 获得s在本次匹配中的出现频率（自增后的）
                int b = ++_c[s];
        		if (b > a) { // 比L中出现的频率要多 => invalid
            	    valid = false;
                    break;
        		}
                ++wc;
        	}
        	// 判断wc == n因为可能S太短导致已匹配的word数不够
        	if (valid && wc == n)
        		result.push_back(i);
        }
        return result;
    }
};