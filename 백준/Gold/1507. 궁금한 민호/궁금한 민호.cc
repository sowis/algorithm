#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	scanf("%d", &N);

	vector<vector<int>> board(N, vector<int>(N));
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			scanf("%d", &board[a][b]);
		}
	}

	/* 모든 점에서 모든 점까지의 각 최단거리가 처음 주어진 도로의 이동 시간 정보와 다르면 불가능 */
	vector<vector<int>> min_board = board;
	for (int m = 0; m < N; ++m) {
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				min_board[a][b] = min(min_board[a][b], min_board[a][m] + min_board[m][b]);
			}
		}
	}

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			if (board[a][b] != min_board[a][b]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	/*********************************************************************************************/

	/* 돌아가지 않아도 되는 경로는 제거 */
	vector<vector<int>> targets = board;
	for (int m = 0; m < N; ++m) {
		for (int a = 0; a < N; ++a) {
			if (a == m) {
				continue;
			}

			for (int b = 0; b < N; ++b) {
				if (b == m || b == a) {
					continue;
				}

				if (board[a][b] == board[a][m] + board[m][b]) {
					targets[a][b] = 0;
				}
			}
		}
	}
	/************************************/

	int result = 0;
	for (int a = 0; a < N; ++a) {
		for (int b = a; b < N; ++b) {
			result += targets[a][b];
		}
	}

	printf("%d\n", result);

	return 0;
}