#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, 1} };
constexpr char directions_char[4] = { 'D', 'R', 'U', 'R' };

int R, C;
int board[1000][1000];

int main(void) {
	scanf("%d%d", &R, &C);

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	vector<char> result;
	if (R % 2) { // 세로 칸 수가 홀수면 모든 칸을 다 지나감
		int current_y = 0;
		while (current_y < R) {
			for (int x = 0; x < C - 1; ++x) {
				result.push_back('R');
			}

			result.push_back('D');
			++current_y;
			if (current_y == R) {
				break;
			}

			for (int x = 0; x < C - 1; ++x) {
				result.push_back('L');
			}

			result.push_back('D');
			++current_y;
		}
	}
	else if (C % 2) { // 가로칸 수가 홀수면 모든 칸을 다 지나감
		int current_x = 0;
		while (current_x < C) {
			for (int y = 0; y < R - 1; ++y) {
				result.push_back('D');
			}

			result.push_back('R');
			++current_x;
			if (current_x == C) {
				break;
			}

			for (int y = 0; y < R - 1; ++y) {
				result.push_back('U');
			}

			result.push_back('R');
			++current_x;
		}
	}
	else { // 가로/세로 둘다 짝수일 때
		int remove_y = -1, remove_x = -1;
		int remove_value = 987654321;

		/* 포기할 칸 찾기 */
		for (int y = 0; y < R; ++y) {
			for (int x = 0; x < C; ++x) {
				if ((y + x) % 2 == 0) {
					continue;
				}
				
				if (board[y][x] < remove_value) {
					remove_value = board[y][x];
					remove_y = y;
					remove_x = x;
				}
			}
		}
		/*****************/

		int current_y = 0;
		/* 포기할 칸에 도달하기 전 */
		while (current_y != remove_y && current_y + 1 != remove_y) {
			for (int x = 0; x < C - 1; ++x) {
				result.push_back('R');
			}

			result.push_back('D');

			for (int x = 0; x < C - 1; ++x) {
				result.push_back('L');
			}

			result.push_back('D');

			current_y += 2;
		}
		/**************************/

		int current_x = 0;
		bool after_remove_block = false;

		/* 제거할 블록이 있는 라인 처리 */
		while (current_x < C) {
			if (after_remove_block == false) {
				if (remove_y == current_y + 1 && remove_x == current_x) {
					result.push_back('R');
					result.push_back('D');
					result.push_back('R');
				}
				else if (remove_y == current_y && remove_x == current_x + 1) {
					result.push_back('D');
					result.push_back('R');
					result.push_back('R');
				}
				else {
					result.push_back('D');
					result.push_back('R');
					result.push_back('U');
					result.push_back('R');
					current_x += 2;
					continue;
				}

				after_remove_block = true;
				current_x += 2;
			}
			else {
				result.push_back('U');
				result.push_back('R');
				result.push_back('D');
				result.push_back('R');
				current_x += 2;
			}

			if (current_x == C) {
				result.pop_back();
				result.push_back('D');
			}
		}

		current_y += 2;
		/**********************************/

		/* 블럭 제거 이후 */
		while (current_y < R) {
			for (int x = 0; x < C - 1; ++x) {
				result.push_back('L');
			}

			result.push_back('D');

			for (int x = 0; x < C - 1; ++x) {
				result.push_back('R');
			}

			result.push_back('D');

			current_y += 2;
		}
		/******************/
	}

	result.pop_back();

	for (const char rst : result) {
		printf("%c", rst);
	}

	return 0;
}