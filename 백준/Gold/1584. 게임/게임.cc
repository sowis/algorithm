#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int SAFE = 0;
constexpr int DANGER = 1;
constexpr int DEATH = 2;

typedef struct _data {
	int y;
	int x;
	int dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int board[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x2 < x1) {
			swap(x1, x2);
		}

		if (y2 < y1) {
			swap(y1, y2);
		}

		for (int y = y1; y <= y2; ++y) {
			for (int x = x1; x <= x2; ++x) {
				board[y][x] = max(board[y][x], DANGER);
			}
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x2 < x1) {
			swap(x1, x2);
		}

		if (y2 < y1) {
			swap(y1, y2);
		}

		for (int y = y1; y <= y2; ++y) {
			for (int x = x1; x <= x2; ++x) {
				board[y][x] = max(board[y][x], DEATH);
			}
		}
	}

	vector<vector<int>> distances(501, vector<int>(501, 1987654321));
	distances[0][0] = 0;
	priority_queue<Data> q;
	q.push({ 0, 0, 0 });
	
	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y > 500 || next_x < 0 || next_x > 500) {
				continue;
			}

			if (board[next_y][next_x] == DEATH) {
				continue;
			}

			const int next_dist = d.dist + board[next_y][next_x];
			if (next_dist >= distances[next_y][next_x]) {
				continue;
			}

			distances[next_y][next_x] = next_dist;
			q.push({ next_y, next_x, next_dist });
		}
	}

	if (distances[500][500] == 1987654321) {
		cout << "-1\n";
	}
	else {
		cout << distances[500][500];
	}

	return 0;
}