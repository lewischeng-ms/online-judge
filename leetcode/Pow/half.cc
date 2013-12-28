class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / x / pow(x, -(n + 1));
        double res = pow(x, n >> 1);
        res *= res;
        if (n & 1)
            res *= x;    
        return res;
    }
};