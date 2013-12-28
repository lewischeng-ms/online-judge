// 硬币问题：问最少需要几枚硬币 
#include <iostream>
#include <vector>

using namespace std;

int kinds[6] = { 500, 100, 50, 10, 5, 1 };

int exchange(int counts[6], int sum) {
	int count = 0;
	int index = 0;
	while (sum > 0 && index < 6) {
		int t = min(sum / kinds[index], counts[index]);
		count += t;
		sum -= t * kinds[index];
		++index;
	}
	return sum == 0 ? count : -1;
}

int main() {
	int kinds[6] = { 2, 0, 3, 1, 2, 3 };
	cout << exchange(kinds, 620) << endl;
	return 0;
}