#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

constexpr int directions[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

constexpr int EMPTY = 0;
constexpr int WALL = 1;
constexpr int START_POS = 2;

constexpr char keys[4] = { 'W', 'A', 'S', 'D' };

int N, M;
vector<vector<int>> board;
int cur_y, cur_x;
unordered_map<char, string> assignments;

bool event_check(const char last_input, const char cur_input, const char me) {
	if (assignments[me] == "Down") {
		return last_input != me && cur_input == me;
	}
	else if (assignments[me] == "Stay") {
		return last_input == me && cur_input == me;
	}
	else if (assignments[me] == "Up") {
		return last_input == me && cur_input != me;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];

			if (board[y][x] == START_POS) {
				cur_y = y;
				cur_x = x;
				board[y][x] = EMPTY;
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		string assignment;
		cin >> assignment;

		assignments[keys[i]] = assignment;
	}

	char last_key = -1;
	for (int i = 0; i < M; ++i) {
		char key;
		cin >> key;

		for (int target_key_idx = 0; target_key_idx < 4; ++target_key_idx) {
			if (event_check(last_key, key, keys[target_key_idx]) == false) {
				continue;
			}

			const int next_y = cur_y + directions[target_key_idx][0];
			const int next_x = cur_x + directions[target_key_idx][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
				continue;
			}

			if (board[next_y][next_x] == WALL) {
				continue;
			}

			cur_y = next_y;
			cur_x = next_x;
		}

		last_key = key;
	}

	cout << cur_y + 1 << " " << cur_x + 1;

	return 0;
}