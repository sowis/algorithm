#include <cstdio>
#include <vector>

using namespace std;

int board[5][5];
bool check[5][5];

bool bingo(void) {
	int bingo_count = 0;

	for (int y = 0; y < 5; ++y) {
		bool result = true;
		for (int x = 0; x < 5; ++x) {
			if (check[y][x] == false) {
				result = false;
				break;
			}
		}

		if (result) {
			++bingo_count;
		}
	}

	for (int x = 0; x < 5; ++x) {
		bool result = true;
		for (int y = 0; y < 5; ++y) {
			if (check[y][x] == false) {
				result = false;
				break;
			}
		}

		if (result) {
			++bingo_count;
		}
	}

	bool result = true;
	for (int i = 0; i < 5; ++i) {
		if (check[i][i] == false) {
			result = false;
			break;
		}
	}

	if (result) {
		++bingo_count;
	}

	result = true;
	for (int i = 0; i < 5; ++i) {
		if (check[4 - i][i] == false) {
			result = false;
			break;
		}
	}

	if (result) {
		++bingo_count;
	}

	return bingo_count >= 3;
}

pair<int, int> whereis(const int value) {
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			if (board[y][x] == value) {
				return { y, x };
			}
		}
	}

	return { -1, -1 };
}

int main(void) {
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	for (int i = 0; i < 25; ++i) {
		int speak;
		scanf("%d", &speak);

		const pair<int, int> pos = whereis(speak);
		check[pos.first][pos.second] = true;

		if (bingo()) {
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}