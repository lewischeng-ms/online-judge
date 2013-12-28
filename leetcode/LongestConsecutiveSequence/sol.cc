class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if (n < 1) return 0;
        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
        	s.insert(num[i]);
        int result = 0;
        for (int i = 0; i < n; ++i) {
        	// 包含num[i]的LCS长度=
        	// 		包含num[i] - 1的LCS长度 +
        	//		包含num[i] + 1的LCS长度 +
        	//		1
        	// 所以分别向两边延伸计算长度就可以了。
        	// 
        	int lenLeft = 0;
        	unordered_set<int>::iterator it;
        	while ((it = s.find(num[i] - lenLeft - 1)) != s.end()) {
        		// 比如2，3，4，那么从4往左扩展的时候，
        		// 其实和之前2往右扩展，长度是一致的。
        		// 所以2，3就不用再考虑了，直接删掉。
        		s.erase(it);
        		++lenLeft;
        	}
        	int lenRight = 0;
        	while ((it = s.find(num[i] + lenRight + 1)) != s.end()) {
        		s.erase(it);
        		++lenRight;
        	}
        	int len = lenLeft + lenRight + 1;
        	if (len > result)
        		result = len; 
        }
        return result;
    }
};