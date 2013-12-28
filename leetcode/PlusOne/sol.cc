class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int d = c + digits[i];
            if (d > 9) {
                digits[i] = d - 10;
                c = 1;
            } else {
                digits[i] = d;
                c = 0;
                break;
            }
        }
        if (c == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};