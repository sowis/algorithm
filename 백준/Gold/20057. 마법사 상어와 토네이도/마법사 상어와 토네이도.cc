#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

constexpr int directions[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
vector<vector<vector<double>>> tornado(4);

int N;
vector<vector<int>> board;

vector<vector<double>> rotate_90(const vector<vector<double>>& v);
int move_tornado(const int my_y, const int my_x, const int direction);

int main(void) {
	tornado[0] = { {0, 0, 0.02, 0, 0},
		{ 0, 0.1, 0.07, 0.01, 0},
		{0.05, 0, 0, 0, 0},
		{0, 0.1, 0.07, 0.01, 0},
		{0, 0, 0.02, 0, 0} };

	for (int i = 0; i < 3; ++i) {
		tornado[i + 1] = rotate_90(tornado[i]);
	}

	scanf("%d", &N);

	board = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	int result = 0;
	int move_length = 1;
	int my_y = N / 2, my_x = N / 2;
	while (move_length < N) {
		for (int direction = 0; direction < 4; ++direction) {
			for (int i = 0; i < move_length; ++i) {
				my_y += directions[direction][0];
				my_x += directions[direction][1];

				result += move_tornado(my_y, my_x, direction);
			}

			if (direction == 1 || direction == 3) {
				++move_length;
			}
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		my_y += directions[0][0];
		my_x += directions[0][1];

		result += move_tornado(my_y, my_x, 0);
	}

	printf("%d\n", result);

	return 0;
}

vector<vector<double>> rotate_90(const vector<vector<double>>& v) {
	vector<vector<double>> result(v.size(), vector<double>(v.size()));

	for (int y = 0; y < result.size(); ++y) {
		for (int x = 0; x < result.size(); ++x) {
			result[y][x] = v[x][result.size() - 1 - y];
		}
	}

	return result;
}

int move_tornado(const int my_y, const int my_x, const int direction) {
	int result = 0;

	const int alpha_y = my_y + directions[direction][0];
	const int alpha_x = my_x + directions[direction][1];

	const int begin_sand = board[my_y][my_x];

	for (int offset_y = 0; offset_y < 5; ++offset_y) { // tornado
		for (int offset_x = 0; offset_x < 5; ++offset_x) {
			if (tornado[direction][offset_y][offset_x] == 0) {
				continue;
			}

			/* 모래가 옮겨질 곳 */
			const int target_y = my_y + offset_y - 2;
			const int target_x = my_x + offset_x - 2;
			/********************/

			const int moved_sand = (int)floor(tornado[direction][offset_y][offset_x] * begin_sand); // 움직일 모래 양

			/* 모래 옮기기 */
			if (target_y < 0 || target_y >= N || target_x < 0 || target_x >= N) {
				result += moved_sand;
			}
			else {
				board[target_y][target_x] += moved_sand;
			}

			board[my_y][my_x] -= moved_sand;
			/***************/
		}
	}

	/* 남은 모래 y로 옮기기 */
	if (alpha_y < 0 || alpha_y >= N || alpha_x < 0 || alpha_x >= N) {
		result += board[my_y][my_x];
	}
	else {
		board[alpha_y][alpha_x] += board[my_y][my_x];
	}

	board[my_y][my_x] = 0;
	/************************/

	return result;
}