class Solution {
public:
    bool containSameLetters(const string &s1, int l1, int r1, const string &s2, int l2, int r2) {
        vector<int> alpha(26);
		int n = r1 - l1 + 1;
        for (int i = 0; i < n; ++i) {
			int a1 = s1[i + l1] - 'a';
			int a2 = s2[i + l2] - 'a';
			++alpha[a1];
			--alpha[a2];
		}
		for (int i = 0; i < 26; ++i)
			if (alpha[i])
				return false;
		return true;
	}

	bool helper(const string &s1, const string &s2, int l1, int r1, int l2, int r2) {
		//printf("s1: %d-%d, s2: %d-%d\n", l1, r1, l2, r2);
		int n = r1 - l1 + 1;
        if (n != r2 - l2 + 1)
            return false;
        if (n == 1)
            return s1[l1] == s2[l2];
        if (!containSameLetters(s1, l1, r1, s2, l2, r2))
			return false;
		for (int k = 1; k < n; ++k) {
			int newL1 = l1, newL11 = l1 + k;
			int newR1 = l1 + k - 1, newR11 = r1;
			// Case 1: s1[l1, l1 + k - 1] <=> s2[l2, l2 + k - 1]
			int newL2 = l2, newL21 = l2 + k;
			int newR2 = l2 + k - 1, newR21 = r2;
			if (helper(s1, s2, newL1, newR1, newL2, newR2)
				&& helper(s1, s2, newL11, newR11, newL21, newR21))
				return true;
			// Case 2: s1[l1, l1 + k - 1] <=> s2[r2 + 1 - k, r2]
			newL2 = r2 + 1 - k; newL21 = l2;
			newR2 = r2; newR21 = l2 + n - k - 1;
			if (helper(s1, s2, newL1, newR1, newL2, newR2)
				&& helper(s1, s2, newL11, newR11, newL21, newR21))
				return true;
		}
		return false;
	}

    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 < 1 && n2 < 1)
        	return true;
    	return helper(s1, s2, 0, n1 - 1, 0, n2 - 1);
    }
};