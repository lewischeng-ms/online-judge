class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> f(n, 1);
        vector<char> c(n, '1');
        for (int i = 1; i < n; ++i) {
            f[i] = i * f[i - 1];
            c[i] = '1' + i;
        }
        string r; --k;
        for (int i = n - 1; i >= 0; --i) {
            int d = k / f[i];
            k = k % f[i];
            char x = c[d];
            c.erase(c.begin() + d);
            r += x; 
        }
        return r;
    }
};