#include <stdio.h>

void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void rotate(char *str, int n, int k) {
	k %= n;
	int j = 0;
	char x = str[j];
	for (int i = 0; i < n; ++i) {
		j = (j + k) % n;
		swap(&x, str + j);
	}
}

int main() {
	char str[] = "abcdefg";
	rotate(str, 7, 3);
	printf("%s\n", str);
	return 0;
}