class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string res(s);
        // dist between a and g
        // a  g
        // be h
        // c fi
        // d  j
        // int dist = nRows - 1 + nRows - 2 + 1;
        // dist has to be > 1 to avoid forever loop.
        int c = 0;
        int dist = max(1, (nRows << 1) - 2);
        for (int i = 0; i < nRows; ++i) {
            int d1 = ((nRows - i - 1) << 1);
            for (int j = i; j < s.size(); j += dist) {
                res[c++] = s[j];
                
                if (i > 0 && i < nRows - 1) {
                    // int k = j + nRows - i - 1 + nRows - i - 1;
                    int k = j + d1;
                    if (k < s.size())
                        res[c++] = s[k];
                }
            }
        }
        return res;
    }
};