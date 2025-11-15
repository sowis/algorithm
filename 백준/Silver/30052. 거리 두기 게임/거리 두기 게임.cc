#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

int N, M, D;

void solve(const int begin_y, const int begin_x, vector<vector<int>>& max_distances) {
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	queue<Data> q;
	q.push({ begin_y, begin_x, 0 });
	visit[begin_y][begin_x] = true;
	max_distances[begin_y][begin_x] = max(max_distances[begin_y][begin_x], 0);

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (visit[next_y][next_x]) {
				continue;
			}

			const int next_dist = d.dist + 1;
			visit[next_y][next_x] = true;
			max_distances[next_y][next_x] = max(max_distances[next_y][next_x], next_dist);
			q.push({ next_y, next_x, next_dist });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> D;

	vector<vector<int>> max_distances(N, vector<int>(M, 0));
	solve(0, 0, max_distances);
	solve(0, M - 1, max_distances);
	solve(N - 1, 0, max_distances);
	solve(N - 1, M - 1, max_distances);

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (max_distances[y][x] < D) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}