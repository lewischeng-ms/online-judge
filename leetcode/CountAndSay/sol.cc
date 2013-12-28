class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1) {
        	return "1";
        } else {
        	string previous = countAndSay(n - 1);
        	int l = previous.size();
        	int i = 0;
        	string result;
        	while (i < l) {
        		int count = 1;
        		char num = previous[i++];
        		while (i < l && previous[i] == num) {
        			++count;
        			++i;
        		}
        		result += (char)('0' + count);
        		result += num;
        	}
        	return result;
        }
    }
};