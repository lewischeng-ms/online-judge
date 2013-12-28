#include <cstdio>
#include <algorithm>

void solve(int L, int positions[], int n) {
	int min_time = 0;
	int max_time = 0;

	for (int i = 0; i < n; ++i) {
		int position_from_right = L - positions[i];
		// 对于最短时间，只需要使每个蚂蚁往自己最近的边缘移动即可，
		// 因此最短时间是所有蚂蚁中离边缘最短距离的最大值（最后一只蚂蚁掉下去的时间）。
		min_time = std::max(min_time, std::min(positions[i], position_from_right));

		// 蚂蚁相遇并朝反方向走，可以理解为等同于蚂蚁互相交错而过（忽略蚂蚁的不同）
		// 因此最长时间是所有蚂蚁中离边缘最长距离的最大值（最后一只蚂蚁掉下去的时间）。
		max_time = std::max(max_time, std::max(positions[i], position_from_right));
	}

	printf("%d %d\n", min_time, max_time);
}

int main() {
	int num_cases = 0;
	scanf("%d", &num_cases);

	for (int i = 0; i < num_cases; ++i) {
		int L = 0; // Length of the stick in (cm)
		int num_ants = 0;
		scanf("%d%d", &L, &num_ants);
		static int positions[1000000]; // Initial position of each ant
		for (int j = 0; j < num_ants; ++j) {
			int pos = 0;
			scanf("%d", &pos);
			positions[j] = pos;
		}
		solve(L, positions, num_ants);
	}

	return 0;
}