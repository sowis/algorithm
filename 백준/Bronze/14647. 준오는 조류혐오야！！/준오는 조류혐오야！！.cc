#include <cstdio>
#include <vector>

using namespace std;

int get_nine(int num) {
	int result = 0;
	while (num > 0) {
		if (num % 10 == 9) {
			++result;
		}
		
		num /= 10;
	}

	return result;
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int>> board(n, vector<int>(m));
	int nine_count = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			int input;
			scanf("%d", &input);

			board[y][x] = get_nine(input);
			nine_count += board[y][x];
		}
	}

	int nine_line_max = 0;

	for (int y = 0; y < n; ++y) {
		int cur = 0;
		for (int x = 0; x < m; ++x) {
			cur += board[y][x];
		}

		if (cur > nine_line_max) {
			nine_line_max = cur;
		}
	}

	for (int x = 0; x < m; ++x) {
		int cur = 0;
		for (int y = 0; y < n; ++y) {
			cur += board[y][x];
		}

		if (cur > nine_line_max) {
			nine_line_max = cur;
		}
	}


	printf("%d\n", nine_count - nine_line_max);

	return 0;
}