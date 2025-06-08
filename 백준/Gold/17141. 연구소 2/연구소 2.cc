#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N, M;
vector<vector<int>> board;

typedef struct _data {
	int y;
	int x;
	int time;

	bool operator< (const struct _data& d) const {
		return this->time > d.time;
	}
} Data;

int get_mintime(const vector<pair<int, int>>& virous) {
	vector<vector<int>> times(N, vector<int>(N, 987654321));

	priority_queue<Data> q;
	for (const pair<int, int>& p : virous) {
		times[p.first][p.second] = 0;
		q.push({ p.first, p.second, 0 });
	}

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.time > times[d.y][d.x]) {
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) { // out
				continue;
			}

			if (board[next_y][next_x] == 1) { // wall
				continue;
			}

			const int next_time = d.time + 1;
			if (next_time >= times[next_y][next_x]) {
				continue;
			}

			times[next_y][next_x] = next_time;
			q.push({ next_y, next_x, next_time });
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] == 1) {
				continue;
			}

			if (times[y][x] == 987654321) {
				return 987654321;
			}

			result = max(result, times[y][x]);
		}
	}

	return result;
}

int set_virous(vector<pair<int, int>>& virous, const int i = 0, const int virous_count = 0) {
	if (virous_count == M) {
		return get_mintime(virous);
	}

	if (i == N * N) {
		return 987654321;
	}

	const int y = i / N;
	const int x = i % N;

	int result = set_virous(virous, i + 1, virous_count);
	if (board[y][x] == 2) {
		virous.push_back({ y, x });
		result = min(result, set_virous(virous, i + 1, virous_count + 1));
		virous.pop_back();
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &M);

	board = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	vector<pair<int, int>> virous;
	const int result = set_virous(virous);
	
	if (result == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result);
	}

	return 0;
}