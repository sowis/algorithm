#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int directions[2][2] = { {0, 1}, {1, 0} };

int N;
vector<vector<char>> board;
int min_value = numeric_limits<int>::max();
int max_value = numeric_limits<int>::min();

void calculate(const vector<char>& formula) {
	int cur = formula[0] - '0';
	for (int i = 1; i + 1 < formula.size(); i += 2) {
		if (formula[i] == '+') {
			cur += (formula[i + 1] - '0');
		}
		else if (formula[i] == '-') {
			cur -= (formula[i + 1] - '0');
		}
		else if (formula[i] == '*') {
			cur *= (formula[i + 1] - '0');
		}
	}

	min_value = min(min_value, cur);
	max_value = max(max_value, cur);
}

void solve(const int y, const int x, vector<char> &trace) {
	trace.push_back(board[y][x]);

	if (y == N - 1 && x == N - 1) {
		calculate(trace);
		trace.pop_back();
		return;
	}

	for (int i = 0; i < 2; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
			continue;
		}

		solve(next_y, next_x, trace);
	}

	trace.pop_back();
}

int main(void) {
	cin >> N;
	
	board = vector<vector<char>>(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	vector<char> trace;
	solve(0, 0, trace);

	cout << max_value << " " << min_value;

	return 0;
}