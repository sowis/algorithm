#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	int a_idx = 0, b_idx = 0;
	for (a_idx = 0; a_idx < a.size(); ++a_idx) {
		for (b_idx = 0; b_idx < b.size(); ++b_idx) {
			if (a[a_idx] == b[b_idx]) {
				break;
			}
		}

		if (a[a_idx] == b[b_idx]) {
			break;
		}
	}

	vector<vector<char>> board(b.size(), vector<char>(a.size(), '.'));
	for (int i = 0; i < a.size(); ++i) {
		board[b_idx][i] = a[i];
	}

	for (int i = 0; i < b.size(); ++i) {
		board[i][a_idx] = b[i];
	}

	for (int y = 0; y < b.size(); ++y) {
		for (int x = 0; x < a.size(); ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}