#include <iostream>
#include <vector>

using namespace std;

constexpr int single = 0;
constexpr int long_begin = 1;
constexpr int long_length = 2;

int B, X, N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> B >> X >> N;

	vector<vector<int>> board(N, vector<int>(9));
	for (int y = N - 1; y >= 0; --y) { // 위아래 뒤집어서 저장
		for (int x = 0; x < 9; ++x) {
			cin >> board[y][x];
		}
	}

	long long result = 0;
	for (int x = 0; x < 9; ++x) {
		long long begin = 0;
		long long end = 0;

		while (begin < N) {
			vector<int> note_count(3, 0);
			for (end = begin; end < N; ++end) { // 구간 찾기 (0이 아닌 노트가 연속해서 나오는 구간)
				if (board[end][x] == 0) {
					break;
				}

				++note_count[board[end][x]];
			}

			if (note_count[2] == 0) { // 구간에 싱글노트만 있는 경우
				result += note_count[1] * 100;
			}
			else if (note_count[2] == 2) { // 구간이 롱노트일 경우
				result += 80;
				result += (end - begin) * X / 6;
			}
			else { // 구간이 롱노트의 시작만 보이거나 끝만 보이는 경우
				result += (end - begin) * X / 6;

				if (board[begin][x] == 2 && ((begin + 1 == N) || (board[begin + 1][x] != 0))) {
					result += 80;
				}
			}

			begin = end + 1;
		}
	}

	cout << result;

	return 0;
}