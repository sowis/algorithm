#include <iostream>
#include <vector>

using namespace std;

int horizontal = 0;
int vertical = 1;
int diagonal = 2;

vector<vector<int>> move_to(3);
int directions[3][2] = { {0, 1}, {1, 0}, {1, 1} };
vector<vector<pair<int, int>>> must_empty(3);

int N;
vector<vector<int>> board;
vector<vector<vector<long long>>> cache; // y, x, 방향

bool can_move(const int y, const int x, const int direction) {
	for (const pair<int, int>& empty_check : must_empty[direction]) {
		const int check_y = y + empty_check.first;
		const int check_x = x + empty_check.second;

		if (check_y >= N || check_x >= N) {
			return false;
		}

		if (board[check_y][check_x] == 1) {
			return false;
		}
	}

	return true;
}

int main(void) {
	move_to[horizontal] = { horizontal, diagonal };
	move_to[vertical] = { vertical, diagonal };
	move_to[diagonal] = { horizontal, vertical, diagonal };

	must_empty[horizontal] = { {0, 1} };
	must_empty[vertical] = { {1, 0} };
	must_empty[diagonal] = { {0, 1}, {1, 0}, {1, 1} };

	cin >> N;
	board = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	cache = vector<vector<vector<long long>>>(N, vector<vector<long long>>(N, vector<long long>(3, 0)));
	cache[0][1][horizontal] = 1;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			for (int i = 0; i < 3; ++i) {
				for (const int direction : move_to[i]) {
					if (can_move(y, x, direction) == false) {
						continue;
					}

					const int next_y = y + directions[direction][0];
					const int next_x = x + directions[direction][1];
					cache[next_y][next_x][direction] += cache[y][x][i];
				}
			}
		}
	}

	long long result = 0;
	for (int d = 0; d < 3; ++d) {
		result += cache[N - 1][N - 1][d];
	}

	cout << result;

	return 0;
}