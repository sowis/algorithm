#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N, M, K;
vector<pair<int, int>> q[3002];
vector<vector<int>> board;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	board = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < K; ++i) {
		int y, x, p;
		cin >> y >> x >> p;

		q[p + 1].push_back({ y - 1, x - 1 });
		board[y - 1][x - 1] = p + 1;
	}

	for (int radio = 3001; radio >= 2; --radio) {
		for (const pair<int, int>& p : q[radio]) {
			for (int i = 0; i < 4; ++i) {
				const int next_y = p.first + directions[i][0];
				const int next_x = p.second + directions[i][1];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (board[next_y][next_x] >= radio - 1) {
					continue;
				}

				board[next_y][next_x] = radio - 1;
				q[radio - 1].push_back({ next_y, next_x });
			}
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] > 0) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}