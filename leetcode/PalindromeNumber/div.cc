class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int y = 0;
        int k = x;
        while (k > 0) {
            y = y * 10 + (k % 10);
            k /= 10;
        }
        return x == y;
    }
};