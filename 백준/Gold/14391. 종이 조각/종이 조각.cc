#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<char>> board;
int result = 0;

void slice(vector<vector<bool>> &visit, const int current_y, const int current_x, const int current_sum) {
	if (current_y >= N) {
		result = max(result, current_sum);
		return;
	}

	if (current_x >= M) {
		slice(visit, current_y + 1, 0, current_sum);
		return;
	}

	if (visit[current_y][current_x]) {
		slice(visit, current_y, current_x + 1, current_sum);
		return;
	}

	visit[current_y][current_x] = true;

	/* 1칸짜리 */
	slice(visit, current_y, current_x + 1, current_sum + board[current_y][current_x] - '0');
	/***********/

	/* y축 블록 */
	int y_length = 2;
	int cur_num = board[current_y][current_x] - '0';
	while (true) {
		if ((current_y + y_length - 1 >= N) || visit[current_y + y_length - 1][current_x]) {
			for (int y = current_y + 1; y < current_y + y_length - 1; ++y) {
				visit[y][current_x] = false;
			}

			break;
		}

		cur_num *= 10;
		cur_num += board[current_y + y_length - 1][current_x] - '0';
		visit[current_y + y_length - 1][current_x] = true;
		slice(visit, current_y, current_x + 1, current_sum + cur_num);
		++y_length;
	}
	/************/

	/* x축 블록 */
	int x_length = 2;
	cur_num = board[current_y][current_x] - '0';
	while (true) {
		if ((current_x + x_length - 1 >= M) || visit[current_y][current_x + x_length - 1]) {
			for (int x = current_x + 1; x < current_x + x_length - 1; ++x) {
				visit[current_y][x] = false;
			}

			break;
		}

		cur_num *= 10;
		cur_num += board[current_y][current_x + x_length - 1] - '0';
		visit[current_y][current_x + x_length - 1] = true;
		slice(visit, current_y, current_x + x_length, current_sum + cur_num);
		++x_length;
	}
	/***********/

	visit[current_y][current_x] = false;
}

void slice(void) {
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	slice(visit, 0, 0, 0);
}

int main(void) {
	cin >> N >> M;

	board = vector<vector<char>>(N, vector<char>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	slice();

	cout << result;

	return 0;
}