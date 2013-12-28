// 从序列中跳出若干数，使其和恰好为k
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int dep, int max_dep, const vector<int> &vec, int sum) {
	if (dep == max_dep)
		return sum == 0;
	return /* 不加上vec[dep] */dfs(dep + 1, max_dep, vec, sum) ||
		/* 加上vec[dep] */dfs(dep + 1, max_dep, vec, sum - vec[dep]);
}

int main() {
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(4);
	A.push_back(7);
	int n = A.size();
	cout << dfs(0, n, A, 13) << endl;
	cout << dfs(0, n, A, 15) << endl;
	return 0;
}