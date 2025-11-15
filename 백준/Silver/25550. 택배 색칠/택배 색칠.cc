#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<long long>> board(N, vector<long long>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	long long result = 0;
	for (int y = 1; y < N - 1; ++y) {
		for (int x = 1; x < M - 1; ++x) {
			long long cur = board[y][x] - 1;
			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				cur = max(0LL, min(cur, board[next_y][next_x]));
			}

			result += cur;
		}
	}
	
	cout << result;

	return 0;
}