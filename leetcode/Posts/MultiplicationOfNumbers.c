#include <stdio.h>

void array_multiplication(int A[], int OUTPUT[], int n) {
	for (int i = 0; i < n; ++i)
		OUTPUT[i] = 1;
	// After: OUTPUT=[1,...,1]
	for (int i = 1; i < n; ++i) {
		OUTPUT[i] *= OUTPUT[i - 1] * A[i - 1];
		A[i - 1] = A[i];
	}
	A[n - 1] = 1;
	// After: OUTPUT=[1,A[0],A[0]A[1],...,A[0]...A[n-2]]
	// 		  A=[A[1],A[2],...A[n-1],1]
	for (int i = n - 2; i >= 0; --i)
		A[i] *= A[i + 1];
	// After: A[1]...A[n-1], A[2]...A[n-1],A[3]...A[n-1],...,A[n-1],1
	for (int i = 0; i < n; ++i)
		OUTPUT[i] *= A[i];
}

int main() {
	int A[] = { 4, 3, 2, 1, 2 };
	int OUTPUT[5];
	array_multiplication(A, OUTPUT, 5);
	for (int i = 0; i < 5; ++i)
		printf("%d ", OUTPUT[i]);
	printf("\n");
	return 0;
}

// The code in http://leetcode.com/2010/04/multiplication-of-numbers.html
// is more concise!