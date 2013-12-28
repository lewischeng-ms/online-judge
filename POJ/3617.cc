#include <cstdio>

char str[2000 + 1];

int main() {
	int num_letters = 0;
	scanf("%d", &num_letters);
	for (int i = 0; i < num_letters; ++i)
		scanf("%s", &str[i]);
	int k = 0;
	int p = 0, q = num_letters - 1;
	while (p <= q) {
		bool left = true;
		// 相同的话必须一直向内比较，尽可能使小的字符越早被选中。
		int pp = p, qq = q;
		while (pp < qq) {
			if (str[pp] < str[qq])
				break;
			if (str[pp] > str[qq]) {
				left = false;
				break;
			}
			++pp;
			--qq;
		}
		if (left)
			putchar(str[p++]);
		else
			putchar(str[q--]);
		++k;
		if (k % 80 == 0)
			putchar('\n');
	}
	putchar('\n');
	return 0;
}