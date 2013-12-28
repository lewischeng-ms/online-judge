class Solution {
public:
    int toInt(vector<int> &v) {
		int result = 0;
		for (int i = 0; i < v.size(); ++i)
			result = (result << 1) + v[i];
		return result;
	}

    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> check;
        vector<int> v(n);
        int lastFlip = -1;
        vector<int> result;
        result.push_back(0);
        check.insert(0);
        while (true) {
        	int i;
        	for (i = n - 1; i >= 0; --i) {
        		if (i == lastFlip)
        			continue;
        		v[i] = 1 - v[i];
        		int x = toInt(v);
        		if (check.find(x) == check.end()) {
        			check.insert(x);
        			result.push_back(x);
        			lastFlip = i;
        			break;
        		}
        		v[i] = 1 - v[i]; // restore
        	}
        	if (i == -1) break; // No bit could be flipped.
        }
        return result;
    }
};