#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<vector<char>> board;

int main(void) {
	cin >> K >> N;

	vector<char> up(K);
	for (int i = 0; i < K; ++i) {
		up[i] = 'A' + i;
	}

	vector<char> down(K);
	for (char& c : down) {
		cin >> c;
	}

	board = vector<vector<char>>(N, vector<char>(K - 1));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < K - 1; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; board[y][0] != '?'; ++y) {
		for (int x = 0; x < K - 1; ++x) {
			if (board[y][x] == '*') {
				continue;
			}

			swap(up[x], up[x + 1]);
		}
	}

	for (int y = N - 1; board[y][0] != '?'; --y) {
		for (int x = 0; x < K - 1; ++x) {
			if (board[y][x] == '*') {
				continue;
			}

			swap(down[x], down[x + 1]);
		}
	}

	vector<char> result(K - 1);
	for (int i = 0; i < K - 1; ++i) {
		if (up[i] == down[i]) {
			result[i] = '*';
		}
		else if (up[i] == down[i + 1] && up[i + 1] == down[i]) {
			result[i] = '-';
			swap(up[i], up[i + 1]);
		}
		else {
			for (int k = 0; k < K - 1; ++k) {
				cout << 'x';
			}

			return 0;
		}
	}

	for (const char c : result) {
		cout << c;
	}

	return 0;
}