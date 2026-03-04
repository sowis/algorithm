#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int WHITE = 0;
constexpr int BLACK = 1;

constexpr int directions[2][2] = { {0, 1}, {1, 0} };

vector<vector<long long>> board;
vector<vector<int>> color;
vector<vector<vector<long long>>> result; // [y][x][0 = 최소값, 1 = 최대값]

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	board = vector<vector<long long>>(N, vector<long long>(M));
	color = vector<vector<int>>(N, vector<int>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> color[y][x];
		}
	}

	result = vector<vector<vector<long long>>>(N, vector<vector<long long>>(M, vector<long long>(2)));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			result[y][x][0] = numeric_limits<long long>::max();
			result[y][x][1] = numeric_limits<long long>::min();
		}
	}

	result[0][0][0] = board[0][0];
	result[0][0][1] = board[0][0];

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			for (int minmax = 0; minmax < 2; ++minmax) {
				for (int i = 0; i < 2; ++i) {
					const int next_y = y + directions[i][0];
					const int next_x = x + directions[i][1];

					if (next_y >= N || next_x >= M) {
						continue;
					}

					long long next_value = result[y][x][minmax] + board[next_y][next_x];
					if (color[next_y][next_x] == BLACK) {
						next_value *= -1;
					}

					result[next_y][next_x][0] = min(result[next_y][next_x][0], next_value);
					result[next_y][next_x][1] = max(result[next_y][next_x][1], next_value);
				}
			}
		}
	}

	cout << result[N - 1][M - 1][1];

	return 0;
}