// 迷宫最短路径
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfs(const vector<vector<char> > &map, int sx, int sy) {
	int N = map.size();
	int M = map[0].size();

	vector<vector<bool> > visited(N, vector<bool>(M, false));

	typedef pair<int, int> position_t;

	queue<position_t> current_que;
	queue<position_t> next_que;
	current_que.push(make_pair(sx, sy));

	int level = 0;

	while (!current_que.empty()) {
		position_t pos = current_que.front();
		current_que.pop();

		// Check if pos is valid
		if (pos.first < 0 || pos.first >= N ||
			pos.second < 0 || pos.second >= M)
			goto CONT;

		// Check if pos is visited
		if (visited[pos.first][pos.second])
			goto CONT;

		visited[pos.first][pos.second] = true;

		// Check if pos is wall
		if (map[pos.first][pos.second] == '#')
			goto CONT;

		// Check if pos is goal
		if (map[pos.first][pos.second] == 'G')
			return level;

		next_que.push(make_pair(pos.first - 1, pos.second));
		next_que.push(make_pair(pos.first + 1, pos.second));
		next_que.push(make_pair(pos.first, pos.second - 1));
		next_que.push(make_pair(pos.first, pos.second + 1));

CONT:
		if (current_que.empty()) {
			++level;
			current_que.swap(next_que); // enabled in c++11
			//swap(current_que, next_que);
		}
	}

	return -1;
}

int main() {
	int N = 10, M = 10;
	char A[][10 + 1 /* '\0' */] = {
		"#S######.#",
		"......#..#",
		".#.##.##.#",
		".#........",
		"##.##.####",
		"....#....#",
		".#######.#",
		"....#.....",
		".####.###.",
		"....#...G#"
	};
	vector<vector<char> > map(10, vector<char>(10));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			map[i][j] = A[i][j];

	cout << bfs(map, 0, 1) << endl;
	return 0;
}