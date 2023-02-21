#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int C, R;
int K;
vector<vector<int>> board;

int next_direction(const int y, const int x, const int d) {
	const int next_y = y + directions[d][0];
	const int next_x = x + directions[d][1];

	if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
		return (d + 1) % 4;
	}

	if (board[next_y][next_x] != -1) {
		return (d + 1) % 4;
	}

	return d;
}

int main(void) {
	scanf("%d%d", &C, &R);
	scanf("%d", &K);

	if (K > C * R) {
		printf("0\n");
		return 0;
	}

	board = vector<vector<int>>(R, vector<int>(C, -1));
	int current = 1;
	int y = 0, x = 0;
	int d = 0;

	while (current != K) {
		board[y][x] = current;
		d = next_direction(y, x, d);
		y += directions[d][0];
		x += directions[d][1];
		++current;
	}

	printf("%d %d\n", x + 1, y + 1);

	return 0;
}