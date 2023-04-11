#include <cstdio>
#include <vector>

using namespace std;

vector<int> psum(101);

void test_case(void) {
	psum[0] = 0;
	for (int i = 1; i < 101; ++i) {
		psum[i] = psum[i - 1] + i;
	}

	int M, N;
	scanf("%d%d", &M, &N);

	vector<vector<int>> board(M, vector<int>(N));
	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	int result = 0;

	for (int x = 0; x < N; ++x) {
		int box_count = 0;
		int box_pos_sum = 0;
		for (int y = 0; y < M; ++y) {
			if (board[y][x] == 1) {
				++box_count;
				box_pos_sum += M - 1 - y;
			}
		}

		if (box_count > 0) {
			result += box_pos_sum - psum[box_count - 1];
		}
	}

	printf("%d\n", result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}