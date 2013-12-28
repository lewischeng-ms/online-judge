#include <stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void sort1(int a[], int n) {
	int i = 0;
	while (i < n) {
		int j = i + 1;
		if (j < n && a[i] > a[j])
			swap(a, i, j);
		int k = i - 1;
		if (k >= 0 && a[i] > a[k])
			swap(a, i, k);
		i += 2;
	}
}

int main() {
	//int a[] = { 1, 2, 3, 4, 5 };
	int a[] = { 2, 3, 1, 4, 5 };
	int n = 5;
	sort1(a, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}