const char *thousands[] = { "", "M", "MM", "MMM" };
const char *hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const char *tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const char *digits[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
	string result;
        int thousand = num / 1000;
	result += thousands[thousand];
	num %= 1000;

	int hundred = num / 100;
	result += hundreds[hundred];
	num %= 100;

	int ten = num / 10;
	result += tens[ten];
	num %= 10;

	int digit = num;
	result += digits[digit];

	return result;
    }
};