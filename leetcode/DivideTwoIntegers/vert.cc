class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool negative = false;
	if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
		negative = true;
	long long a = dividend; a = abs(a);
	long long b = abs(divisor); b = abs(b);
	int  m = 0; // multiplier
	// 基本思想：如计算131 / 5
	// (1) a = 131 - 5 * 2^4 = 131 - 80 = 51, m = m + 2^4 = 16
	// (2) a = 51 - 5 * 2^3 = 51 - 40 = 11, m = m + 2^3 = 24
	// (3) a = 11 - 5 * 2^1 = 11 - 10 = 1, m = m + 2^1 = 26
	// (4) a = 1 < 5, m = m + 0 = 26
	while (a >= b) {
		int c = 1;
		long long e = b;
		while ((e << 1) <= a) {
			e <<= 1;
			c <<= 1;
		}
		a -= e;
		m += c;
	}
	
	return negative ? -m : m;
    }
};