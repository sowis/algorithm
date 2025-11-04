#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int K;
	cin >> K;

	vector<vector<char>> board(N + 1, vector<char>(M + 1));
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> board[y][x];
		}
	}

	vector<vector<vector<int>>> psum(N + 1, vector<vector<int>>(M + 1, vector<int>(3, 0)));

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			psum[y][x][0] = psum[y][x - 1][0] + psum[y - 1][x][0] - psum[y - 1][x - 1][0];
			psum[y][x][1] = psum[y][x - 1][1] + psum[y - 1][x][1] - psum[y - 1][x - 1][1];
			psum[y][x][2] = psum[y][x - 1][2] + psum[y - 1][x][2] - psum[y - 1][x - 1][2];

			if (board[y][x] == 'J') {
				++psum[y][x][0];
			}
			else if (board[y][x] == 'O') {
				++psum[y][x][1];
			}
			else {
				++psum[y][x][2];
			}
		}
	}

	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int jungle = psum[c][d][0] - psum[c][b - 1][0] - psum[a - 1][d][0] + psum[a - 1][b - 1][0];
		int ocean = psum[c][d][1] - psum[c][b - 1][1] - psum[a - 1][d][1] + psum[a - 1][b - 1][1];
		int ice = psum[c][d][2] - psum[c][b - 1][2] - psum[a - 1][d][2] + psum[a - 1][b - 1][2];

		cout << jungle << " " << ocean << " " << ice << "\n";
	}

	return 0;
}