#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<long long, std::vector<long long>, std::greater<long long> > planks;

int main() {
	int N = 0;
	scanf("%d", &N);
	if (N == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		int plank = 0;
		scanf("%d", &plank);
		planks.push(plank);
	}
	long long sum = 0;
	while (planks.size() > 1) {
		long long min_1st = planks.top();
		planks.pop();
		long long min_2nd = planks.top();
		planks.pop();
		long long temp = min_1st + min_2nd;
		sum += temp;
		planks.push(temp);
	}
	printf("%lld\n", sum);
	return 0;
}