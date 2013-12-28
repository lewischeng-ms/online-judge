class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = abs(x);
        int r = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            r = r * 10 + d;
        }
        
        return x >= 0 ? r : -r;
    }
};