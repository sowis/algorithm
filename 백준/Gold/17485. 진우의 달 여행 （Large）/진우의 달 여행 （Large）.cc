#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[3][2] = { {1, 0}, {1, -1}, {1, 1} };

int N, M;
vector<vector<int>> board;
vector<vector<vector<int>>> min_dist; // y, x, 마지막으로 움직인 방향 = 최소거리

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M));
	min_dist = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(3, 987654321)));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int x = 0; x < M; ++x) {
		for (int i = 0; i < 3; ++i) {
			min_dist[0][x][i] = board[0][x];
		}
	}

	for (int y = 0; y < N - 1; ++y) {
		for (int x = 0; x < M; ++x) {
			for (int i = 0; i < 3; ++i) {
				for (int d = 0; d < 3; ++d) {
					if (i == d) {
						continue;
					}

					const int next_y = y + directions[d][0];
					const int next_x = x + directions[d][1];

					if (next_x < 0 || next_x >= M) {
						continue;
					}

					min_dist[next_y][next_x][d] = min(min_dist[next_y][next_x][d], min_dist[y][x][i] + board[next_y][next_x]);
				}
			}
		}
	}

	int result = 987654321;
	for (int x = 0; x < M; ++x) {
		for (int i = 0; i < 3; ++i) {
			result = min(result, min_dist[N - 1][x][i]);
		}
	}

	cout << result;

	return 0;
}