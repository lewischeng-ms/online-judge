class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = min(x, 46340); // sqrt(INT_MAX)
        while (l < r - 1) {
            int m = (l + r) >> 1;
            int p = m * m;
            if (p == x)
                return m;
            else if (p < x)
                l = m;
            else
                r = m;
        }
        if (r * r <= x)
            return r;
        return l;
    }
};