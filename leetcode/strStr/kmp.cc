class Solution {
public:
    int next[33000];
    
    void getNext(char *needle, int len) {
        int i = 1, j = 0;
    	next[1] = 0;
		while (i < len) {
			if (j == 0 || needle[i] == needle[j]) {
				++i;
				++j;
				if (needle[i] == needle[j])
					next[i] = next[j];
				else
					next[i] = j;
			} else {
				j = next[j];
			}
		}
	}

	int kmp(char *haystack, char *needle, int len1, int len2) {
		int i = 1, j = 1;
		while (i <= len1 && j <= len2) {
			if (j == 0 || haystack[i] == needle[j]) {
				++i;
				++j;
			} else {
				j = next[j];
			}
		}
		if (j > len2)
			return i - len2;
		else
			return 0;
	}

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        getNext(needle - 1, len2);
        int pos = kmp(haystack - 1, needle - 1, len1, len2);
        return pos == 0 ? NULL : haystack + pos - 1;
    }
};