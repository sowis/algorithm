#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> psum; // (1, 1) 부터 (y, x) 까지의 범위 합

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	board = vector<vector<int>>(N + 2, vector<int>(N + 2, 0));
	psum = vector<vector<int>>(N + 2, vector<int>(N + 2, 0));

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			psum[y][x] = board[y][x] + psum[y - 1][x] + psum[y][x - 1] - psum[y - 1][x - 1];
		}
	}

	int Q;
	cin >> Q;

	while (Q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		const int inner = psum[r2 - 1][c2 - 1] - psum[r1][c2 - 1] - psum[r2 - 1][c1] + psum[r1][c1];
		const int all = psum[r2][c2] - psum[r2][c1 - 1] - psum[r1 - 1][c2] + psum[r1 - 1][c1 - 1];
		const int result = inner * 2 - all;

		cout << result << "\n";
	}

	return 0;
}