#include <algorithm>
#include <cstdio>

int positions[1000];

int main() {
	while (true) {
		int R = -1;
		int n = -1;
		scanf("%d%d", &R, &n);
		if (R == -1 && n == -1)
			return 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &positions[i]);
		std::sort(positions, positions + n);
		int count = 0;
		int j = 0;
		while (j < n) {
			int start = positions[j++]; // The leftmost position not covered
			while (j < n && positions[j] <= start + R)
				++j; // The leftmost position within radius R of start
			int mark = positions[j - 1]; // Newly marked position
			while (j < n && positions[j] <= mark + R)
				++j; // Move to the rightmost position out of radius R of mark
			++count;
		}
		printf("%d\n", count);
	}
}
