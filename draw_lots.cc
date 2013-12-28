// 从一个包含n个数的序列中抽取4个数（可重复），问其和是否可能等于m？
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool binary_search(vector<int> &A, int x) {
	int l = 0;
	int r = A.size() - 1;
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (A[mid] == x)
			return true;
		else if (A[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}

// 复杂度：O(n^2logn)
bool solve(vector<int> &lots, int sum) {
	vector<int> sum2;

	// 枚举任意两数之和
	int n = lots.size();
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			sum2.push_back(lots[i] + lots[j]);

	sort(sum2.begin(), sum2.end());

	// 枚举两个数，然后在sum2数组里二分查找m-两数之和。
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			if (binary_search(sum2, sum - lots[i] - lots[j]))
				return true;

	return false;
}

int main() {
	vector<int> A;
	A.push_back(1);
	A.push_back(3);
	A.push_back(5);
	cout << solve(A, 10) << endl;

	vector<int> B;
	B.push_back(1);
	B.push_back(3);
	B.push_back(5);
	cout << solve(B, 9) << endl;

	return 0;
}