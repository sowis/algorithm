#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int EMPTY = -1;
constexpr int ESCAPE = 1;
constexpr int CANT_ESCAPE = 0;
unordered_map<char, pair<int, int>> directions;

int N, M;
vector<vector<char>> board;
vector<vector<int>> cache;

int solve(const int y, const int x) {
	int& c = cache[y][x];
	if (c != -1) {
		return c;
	}

	c = CANT_ESCAPE;
	const int next_y = y + directions[board[y][x]].first;
	const int next_x = x + directions[board[y][x]].second;
	if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
		return c = ESCAPE;
	}

	return c = solve(next_y, next_x);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	directions['U'] = { -1, 0 };
	directions['R'] = { 0, 1 };
	directions['D'] = { 1, 0 };
	directions['L'] = { 0, -1 };

	cin >> N >> M;
	board = vector<vector<char>>(N, vector<char>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	cache = vector<vector<int>>(N, vector<int>(M, EMPTY));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (cache[y][x] != EMPTY) {
				continue;
			}

			solve(y, x);
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (cache[y][x] == ESCAPE) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}