#include <iostream>
#include <vector>

using namespace std;

int W, S;
vector<vector<char>> board;
vector<vector<vector<char>>> seals;
int p;
vector<vector<bool>> hits;

bool can_hit(const vector<vector<char>>& seal, const int begin_y, const int begin_x) {
	for (int y = 0; y < seal.size(); ++y) {
		for (int x = 0; x < seal[0].size(); ++x) {
			if (seal[y][x] == '.') {
				continue;
			}

			if (board[begin_y + y][begin_x + x] == '.') {
				return false;
			}
		}
	}

	return true;
}

void hit(const vector<vector<char>>& seal, const int begin_y, const int begin_x) {
	for (int y = 0; y < seal.size(); ++y) {
		for (int x = 0; x < seal[0].size(); ++x) {
			if (seal[y][x] == '.') {
				continue;
			}

			hits[begin_y + y][begin_x + x] = true;
		}
	}
}

int main(void) {
	cin >> W >> S;

	board = vector<vector<char>>(W + 22, vector<char>(S + 22, '.'));
	for (int y = 11; y < 11 + W; ++y) {
		for (int x = 11; x < 11 + S; ++x) {
			cin >> board[y][x];
		}
	}

	cin >> p;
	for (int i = 0; i < p; ++i) {
		int r, c;
		cin >> r >> c;

		vector<vector<char>> seal(r, vector<char>(c));
		for (int y = 0; y < r; ++y) {
			for (int x = 0; x < c; ++x) {
				cin >> seal[y][x];
			}
		}

		seals.push_back(seal);
	}
	
	hits = vector<vector<bool>>(W + 22, vector<bool>(S + 22, false));
	for (const vector<vector<char>>& seal : seals) {
		for (int begin_y = 0; begin_y < W + 11; ++begin_y) {
			for (int begin_x = 0; begin_x < S + 11; ++begin_x) {
				if (can_hit(seal, begin_y, begin_x)) {
					hit(seal, begin_y, begin_x);
				}
			}
		}
	}

	for (int y = 0; y < W + 11; ++y) {
		for (int x = 0; x < S + 11; ++x) {
			if (board[y][x] == '#' && hits[y][x] == false) {
				cout << "NIE";
				return 0;
			}
		}
	}

	cout << "TAK";

	return 0;
}