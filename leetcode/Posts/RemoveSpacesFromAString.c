#include <stdio.h>

void removeSpace(char *str) {
	char *set = str, *get = str;
	while (*get) {
		if (*get != ' ')
			*set++ = *get;
		++get;
	}
	*set = '\0';
}

int main() {
	char str[] = "abc de";
	removeSpace(str);
	printf("%s\n", str);
	return 0;
}