class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string::iterator i = s.begin();
	int thousand = 0;
	while (i != s.end() && *i == 'M') {
		++thousand;
		++i;
	}
	int hundred = 0;
	while (i != s.end() && *i == 'C') {
		++hundred;
		++i;
	}
	if (i != s.end() && *i == 'D') {
		hundred = 5 - hundred;
		++i;
	}
	if (i != s.end() && *i == 'M') {
		hundred = 10 - hundred;
		++i;
	}
	while (i != s.end() && *i == 'C') {
		++hundred;
		++i;
	}
	int ten = 0;
	while (i != s.end() && *i == 'X') {
		++ten;
		++i;
	}
	if (i != s.end() && *i == 'L') {
		ten = 5 - ten;
		++i;
	}
	if (i != s.end() && *i == 'C') {
		ten = 10 - ten;
		++i;
	}
	while (i != s.end() && *i == 'X') {
		++ten;
		++i;
	}
	int digit = 0;
	while (i != s.end() && *i == 'I') {
		++digit;
		++i;
	}
	if (i != s.end() && *i == 'V') {
		digit = 5 - digit;
		++i;
	}
	if (i != s.end() && *i == 'X') {
		digit = 10 - digit;
		++i;
	}
	while (i != s.end() && *i == 'I') {
		++digit;
		++i;
	}
	return thousand * 1000 + hundred * 100 + ten * 10 + digit;
    }
};