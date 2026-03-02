#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int DIV = 1000007;
constexpr int directions[2][2] = { {0, 1}, {1, 0} };

int N, M, C;
int board[52][52]; // [y][x] = 오락실id (0이면 오락실X)
int result[52][52][52][52]; // [방문한 오락실 수][마지막 오락실 번호][y][x] = 경로수

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> C;

	for (int i = 0; i < C; ++i) {
		int y, x;
		cin >> y >> x;
		board[y][x] = i + 1;
	}

	if (board[1][1] == 0) {
		result[0][0][1][1] = 1;
	}
	else {
		result[1][board[1][1]][1][1] = 1;
	}

	for (int game_count = 0; game_count <= C; ++game_count) {
		for (int last_id = 0; last_id <= C; ++last_id) {
			for (int y = 1; y <= N; ++y) {
				for (int x = 1; x <= M; ++x) {
					for (int i = 0; i < 2; ++i) {
						const int next_y = y + directions[i][0];
						const int next_x = x + directions[i][1];

						if (board[next_y][next_x] == 0) {
							result[game_count][last_id][next_y][next_x] += result[game_count][last_id][y][x];
							result[game_count][last_id][next_y][next_x] %= DIV;
							continue;
						}
						
						if (board[next_y][next_x] < last_id) { // 오락실번호 역행 불가
							continue;
						}

						result[game_count + 1][board[next_y][next_x]][next_y][next_x] += result[game_count][last_id][y][x];
						result[game_count + 1][board[next_y][next_x]][next_y][next_x] %= DIV;
					}
				}
			}
		}
	}

	for (int game_count = 0; game_count <= C; ++game_count) {
		int result_sum = 0;
		for (int last_id = 0; last_id <= C; ++last_id) {
			result_sum += result[game_count][last_id][N][M];
			result_sum %= DIV;
		}

		cout << result_sum << " ";
	}
	
	return 0;
}