#include <cassert>
#include <cstdio>

char map[100][100 + 1 /* for '\0' */];

// 假设map[x][y]是pond的一部分，
// 那么本次dfs会把该pond中所有元素都设为'.'
void dfs(int x, int y, int N, int M) {
	if (x < 0 || x >= N)
		return;
	if (y < 0 || y >= M)
		return;
	if (map[x][y] == '.')
		return;
	assert(map[x][y] == 'W');
	map[x][y] = '.';
	dfs(x - 1, y - 1, N, M);
	dfs(x, y - 1, N, M);
	dfs(x + 1, y - 1, N, M);
	dfs(x - 1, y, N, M);
	dfs(x + 1, y, N, M);
	dfs(x - 1, y + 1, N, M);
	dfs(x, y + 1, N, M);
	dfs(x + 1, y + 1, N, M);
}

int main() {
	int N = 0, M = 0;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i)
		scanf("%s", map[i]);

	int pond_count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 'W') {
				++pond_count;
				dfs(i, j, N, M);
			}
		}
	}

	printf("%d\n", pond_count);

	return 0;
}