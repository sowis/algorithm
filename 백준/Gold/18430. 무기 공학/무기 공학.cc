#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[4][2][2] = { {{0, -1}, {1, 0}} ,{{0, -1}, {-1, 0}}, {{-1, 0}, {0, 1}}, {{1, 0}, {0, 1}} };

int N, M;
int result = 0;
vector<vector<int>> board;

bool validate(const vector<vector<bool>>& visit, const int y, const int x, const int i) {
	if (visit[y][x]) {
		return false;
	}

	for (int k = 0; k < 2; ++k) {
		const int next_y = y + directions[i][k][0];
		const int next_x = x + directions[i][k][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			return false;
		}

		if (visit[next_y][next_x]) {
			return false;
		}
	}

	return true;
}

int get_score(const int y, const int x, const int i) {
	int score = board[y][x] * 2;
	for (int k = 0; k < 2; ++k) {
		const int next_y = y + directions[i][k][0];
		const int next_x = x + directions[i][k][1];
		score += board[next_y][next_x];
	}

	return score;
}

void solve(vector<vector<bool>>& visit, const int score = 0, const int y = 0, const int x = 0) {
	result = max(result, score);
	if (y == N) {
		return;
	}

	int next_y;
	int next_x;

	if (x == M - 1) {
		next_y = y + 1;
		next_x = 0;
	}
	else {
		next_y = y;
		next_x = x + 1;
	}

	solve(visit, score, next_y, next_x);
	for (int i = 0; i < 4; ++i) {
		if (validate(visit, y, x, i) == false) {
			continue;
		}

		const int next_score = score + get_score(y, x, i);
		visit[y][x] = true;
		for (int k = 0; k < 2; ++k) {
			visit[y + directions[i][k][0]][x + directions[i][k][1]] = true;
		}

		solve(visit, next_score, next_y, next_x);

		visit[y][x] = false;
		for (int k = 0; k < 2; ++k) {
			visit[y + directions[i][k][0]][x + directions[i][k][1]] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	vector<vector<bool>> visit(N, vector<bool>(M, false));
	solve(visit);
	cout << result;

	return 0;
}