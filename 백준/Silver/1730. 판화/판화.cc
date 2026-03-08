#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<int, int>> directions;
vector<vector<char>> board;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	directions['U'] = { -1, 0 };
	directions['D'] = { 1, 0 };
	directions['L'] = { 0, -1 };
	directions['R'] = { 0, 1 };

	int N;
	cin >> N;

	board = vector<vector<char>>(N, vector<char>(N, '.'));

	string operations;
	cin >> operations;

	int cur_y = 0, cur_x = 0;
	for (const char op : operations) {
		const int next_y = cur_y + directions[op].first;
		const int next_x = cur_x + directions[op].second;

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
			continue;
		}

		if (board[cur_y][cur_x] == '.') {
			if (op == 'D' || op == 'U') {
				board[cur_y][cur_x] = '|';
			}
			else {
				board[cur_y][cur_x] = '-';
			}
		}
		else if (board[cur_y][cur_x] == '-') {
			if (op == 'D' || op == 'U') {
				board[cur_y][cur_x] = '+';
			}
		}
		else if (board[cur_y][cur_x] == '|') {
			if (op == 'L' || op == 'R') {
				board[cur_y][cur_x] = '+';
			}
		}

		cur_y = next_y;
		cur_x = next_x;

		if (board[cur_y][cur_x] == '.') {
			if (op == 'D' || op == 'U') {
				board[cur_y][cur_x] = '|';
			}
			else {
				board[cur_y][cur_x] = '-';
			}
		}
		else if (board[cur_y][cur_x] == '-') {
			if (op == 'D' || op == 'U') {
				board[cur_y][cur_x] = '+';
			}
		}
		else if (board[cur_y][cur_x] == '|') {
			if (op == 'L' || op == 'R') {
				board[cur_y][cur_x] = '+';
			}
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cout << board[y][x];
		}
		cout << "\n";
	}

	return 0;
}