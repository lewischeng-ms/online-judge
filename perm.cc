// 产生0...n-1的全排列
#include <algorithm>
#include <iostream>

using namespace std;

void print(int n, int perm[]) {
	for (int i = 0; i < n; ++i)
		cout << perm[i] << " ";
	cout << endl;
}

void recursive(int dep, int max_dep, int perm[], bool used[]) {
	if (dep == max_dep) {
		print(max_dep, perm);
	} else {
		for (int i = 0; i < max_dep; ++i) {
			if (used[i])
				continue;
			perm[dep] = i;
			used[i] = true;
			recursive(dep + 1, max_dep, perm, used);
			used[i] = false;
		}
	}
}

void iterative(int n, int perm[]) {
	for (int i = 0; i < n; ++i)
		perm[i] = i;

	do {
		print(n, perm);
	} while (next_permutation(perm, perm + n));
}

int main() {
	int perm[4];
	bool used[4];
	recursive(0, 4, perm, used);
	cout << "--------\n";
	iterative(4, perm);
	return 0;
}