#include <stdio.h>

int rotated_binary_search(int A[], int N, int key) {
	int l = 0;
	int r = N - 1;
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (A[m] == key)
			return m;
		if (A[l] <= A[m]) {
			if (A[l] <= key && key < A[m])
				r = m - 1;
			else
				l = m + 1;
		} else {
			if (A[m] < key && key <= A[r])
				l = m + 1;
			else
				r = m - 1;
		}
	}
	return -1;
}

int main() {
	int A[] = { 6, 8, 1, 2, 4, 5 };
	printf("%d\n", rotated_binary_search(A, 6, 1));
	return 0;
}