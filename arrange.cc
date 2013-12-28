// 贪心算法经典例子：工作安排
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// pair<start, end>
// 越早结束的工作越先安排
int arrange(vector<pair<int, int> > &tasks) {
	int n = tasks.size();
	int last = 0;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (last < tasks[i].first) {
			++count;
			last = tasks[i].second;
		}
	}
	return count;
}

int main() {
	vector<pair<int, int> > tasks;
	tasks.push_back(make_pair(1, 3));
	tasks.push_back(make_pair(2, 5));
	tasks.push_back(make_pair(4, 7));
	tasks.push_back(make_pair(6, 9));
	tasks.push_back(make_pair(8, 10));
	cout << arrange(tasks) << endl;
	return 0;
}