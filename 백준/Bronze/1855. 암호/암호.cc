#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int K;
	cin >> K;

	string input;
	cin >> input;

	vector<vector<char>> board(input.size() / K, vector<char>(K));
	int idx = 0;
	for (int y = 0; y < board.size(); ++y) {
		for (int x = 0; x < K; ++x) {
			board[y][x] = input[idx];
			++idx;
		}

		++y;
		if (y == board.size()) {
			break;
		}

		for (int x = K - 1; x >= 0; --x) {
			board[y][x] = input[idx];
			++idx;
		}
	}

	for (int x = 0; x < K; ++x) {
		for (int y = 0; y < board.size(); ++y) {
			cout << board[y][x];
		}
	}

	return 0;
}