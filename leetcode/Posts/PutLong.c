#include <stdio.h>

void putLong(unsigned long n) {
	if (n < 10) { // Error: n == 0!
		putchar(n + '0');
	} else {
		putLong(n / 10);
		putchar((n % 10) + '0');
	}
}

int main() {
	putLong(1234);
	return 0;
}