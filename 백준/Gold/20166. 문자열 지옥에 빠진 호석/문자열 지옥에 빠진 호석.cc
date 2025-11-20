#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

constexpr int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int N, M, K;
vector<vector<char>> board;
string target;
unordered_map<string, int> counts;

pair<int, int> move_to(const int y, const int x, const int direction_index) {
	const int next_y = (y + directions[direction_index][0] + N) % N;
	const int next_x = (x + directions[direction_index][1] + M) % M;
	return { next_y, next_x };
}

void solve(const int y, const int x, const string& cur) {
	++counts[cur];

	if (cur.size() == 5) {
		return;
	}

	for (int i = 0; i < 8; ++i) {
		const auto [next_y, next_x] = move_to(y, x, i);
		const char next_char = board[next_y][next_x];
		solve(next_y, next_x, cur + next_char);
	}
}

void solve(const int y, const int x) {
	string cur;
	solve(y, x, cur + board[y][x]);
}

void test_case(void) {
	cin >> target;
	cout << counts[target] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	board = vector<vector<char>>(N, vector<char>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			solve(y, x);
		}
	}

	for (int i = 0; i < K; ++i) {
		test_case();
	}

	return 0;
}