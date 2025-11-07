#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	char W;
	int N;

	cin >> W >> N;

	vector<vector<char>> board(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];

			if (board[y][x] == '1') {
				board[y][x] = '1';
			}
			else if (board[y][x] == '2') {
				board[y][x] = '5';
			}
			else if (board[y][x] == '5') {
				board[y][x] = '2';
			}
			else if (board[y][x] == '8') {
				board[y][x] = '8';
			}
			else {
				board[y][x] = '?';
			}
		}
	}

	vector<vector<char>> result(N, vector<char>(N));
	if (W == 'L' || W == 'R') {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				result[y][(N - 1) - x] = board[y][x];
			}
		}
	}
	else {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				result[(N - 1) - y][x] = board[y][x];
			}
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cout << result[y][x] << " ";
		}

		if (y != N - 1) {
			cout << "\n";
		}
	}

	return 0;
}