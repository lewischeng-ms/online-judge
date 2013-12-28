#include <stdio.h>
#include <ctype.h>

int countNumWords(const char *str) {
	int result = 0;
	while (*str) {
		if (isalpha(*str)) {
			while (isalpha(*str))
				++str;
			++result;
		} else {
			++str;
		}
	}
	return result;
}

int main() {
	printf("%d\n", countNumWords("Hello, my name is John."));
	return 0;
}