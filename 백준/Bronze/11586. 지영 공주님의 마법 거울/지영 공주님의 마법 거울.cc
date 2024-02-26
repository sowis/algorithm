#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<vector<char>> origin(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> origin[y][x];
		}
	}

	int op;
	cin >> op;

	if (op == 1) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cout << origin[y][x];
			}
			cout << "\n";
		}
	}
	else if (op == 2) {
		for (int y = 0; y < N; ++y) {
			for (int x = N - 1; x >= 0; --x) {
				cout << origin[y][x];
			}
			cout << "\n";
		}
	}
	else {
		for (int y = N - 1; y >= 0; --y) {
			for (int x = 0; x < N; ++x) {
				cout << origin[y][x];
			}
			cout << "\n";
		}
	}

	return 0;
}