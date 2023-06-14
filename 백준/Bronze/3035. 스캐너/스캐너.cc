#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int R, C, ZR, ZC;
	cin >> R >> C >> ZR >> ZC;

	vector<string> input(R);
	for (string& s : input) {
		cin >> s;
	}

	vector<vector<char>> result(R * ZR, vector<char>(C * ZC));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			const int begin_y = y * ZR;
			const int begin_x = x * ZC;

			for (int y_offset = 0; y_offset < ZR; ++y_offset) {
				for (int x_offset = 0; x_offset < ZC; ++x_offset) {
					result[begin_y + y_offset][begin_x + x_offset] = input[y][x];
				}
			}
		}
	}

	for (int y = 0; y < R * ZR; ++y) {
		for (int x = 0; x < C * ZC; ++x) {
			cout << result[y][x];
		}

		cout << "\n";
	}

	return 0;
}