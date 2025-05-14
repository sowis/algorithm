#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

typedef struct _data {
	int y;
	int x;
	int change;

	bool operator<(const _data& d) const {
		return this->change > d.change;
	}
} Data;

int main(void) {
	int N;
	cin >> N;

	vector<vector<char>> board(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	vector<vector<int>> min_change(N, vector<int>(N, numeric_limits<int>::max()));
	priority_queue<Data> pq;
	pq.push({ 0, 0, 0 });
	min_change[0][0] = 0;

	while (pq.empty() == false) {
		const Data d = pq.top();
		pq.pop();

		int& c = min_change[d.y][d.x];
		if (c < d.change) {
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
				continue;
			}

			const int next_change = d.change + ((board[next_y][next_x] == '1') ? 0 : 1);

			if (min_change[next_y][next_x] <= next_change) {
				continue;
			}

			min_change[next_y][next_x] = next_change;
			pq.push({ next_y, next_x, next_change });
		}
	}

	cout << min_change[N - 1][N - 1];

	return 0;
}