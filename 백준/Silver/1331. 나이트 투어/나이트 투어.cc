#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid_move(const pair<int, int>& p1, const pair<int, int>& p2) {
	if ((abs(p1.first - p2.first) == 2) && (abs(p1.second - p2.second) == 1)) {
		return true;
	}

	if ((abs(p1.first - p2.first) == 1) && (abs(p1.second - p2.second) == 2)) {
		return true;
	}

	return false;
}

inline pair<int, int> change(const string& pos) {
	return { pos[0] - 'A', pos[1] - '1' };
}

int main(void) {
	vector<vector<bool>> board(6, vector<bool>(6, false));
	string input;
	cin >> input;

	pair<int, int> cur = change(input);
	const pair<int, int> begin = cur;
	board[cur.first][cur.second] = true;

	for (int i = 0; i < 35; ++i) {
		cin >> input;
		pair<int, int> next = change(input);

		if (board[next.first][next.second] == true) {
			cout << "Invalid\n";
			return 0;
		}

		if (is_valid_move(cur, next) == false) {
			cout << "Invalid\n";
			return 0;
		}

		cur = next;
		board[cur.first][cur.second] = true;
	}

	if (is_valid_move(cur, begin) == false) {
		cout << "Invalid\n";
		return 0;
	}

	cout << "Valid\n";

	return 0;
}