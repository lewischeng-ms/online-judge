// 给出一个正整数序列，求其中三个数组成三角形的三边之和最大值
// 若不能组成三角形，则返回0

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 三边能组成三角形的充要条件为：
// 最长边 < 其余两边之和
// 所以先按从小到大排序
// 考虑最大的那根边，显然为了能组成最大三角形，
// 考虑最大边之下，倒数第二、第三大的边，
// 如果他们能组成三角形，那么必然是三边和最大的三角形；
// 如果不能，那说明这个序列中就没有两条边能和当前最大边组成三角形，
// 于是丢弃当前最大边，考虑第二大边，然后重复这个过程。
// 复杂度O(nlogn)+O(n)=O(nlogn)
int triangle(vector<int> &A) {
	sort(A.begin(), A.end());

	int n = A.size();
	if (n < 3)
		return 0;

	int r = n - 1;
	int q = n - 2;
	int p = n - 3;
	while (r > 1) {
		if (A[p] + A[q] > A[r])
			return A[p] + A[q] + A[r];
		--r;
		--q;
		--p;
	}
	return 0;
}

int main() {
	vector<int> A;
	A.push_back(10);
	A.push_back(5);
	A.push_back(3);
	A.push_back(4);
	A.push_back(2);
	cout << triangle(A) << endl;

	vector<int> B;
	B.push_back(10);
	B.push_back(5);
	B.push_back(4);
	B.push_back(20);
	cout << triangle(B) << endl;
	return 0;
}