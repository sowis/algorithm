#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main(void) {
	int N, num;
	scanf("%d%d", &N, &num);

	vector<vector<int>> arr(N, vector<int>(N));
	int giver = 1;
	int current_y = N / 2;
	int current_x = N / 2;
	arr[current_y][current_x] = giver;
	++giver;

	int length = 1;
	int direction = 0;
	int target_y = 0, target_x = 0;

	while (length < N) {
		for (int i = 1; i <= length; ++i) {
			arr[current_y + directions[direction][0] * i][current_x + directions[direction][1] * i] = giver;
			++giver;
		}

		current_y += directions[direction][0] * length;
		current_x += directions[direction][1] * length;
		direction = (direction + 1) % 4;

		for (int i = 1; i <= length; ++i) {
			arr[current_y + directions[direction][0] * i][current_x + directions[direction][1] * i] = giver;
			++giver;
		}

		current_y += directions[direction][0] * length;
		current_x += directions[direction][1] * length;
		direction = (direction + 1) % 4;
		++length;
	}

	for (int i = 1; i < length; ++i) {
		arr[current_y + directions[direction][0] * i][current_x + directions[direction][1] * i] = giver;
		++giver;
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (arr[y][x] == num) {
				target_y = y;
				target_x = x;
			}

			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	
	printf("%d %d\n", target_y + 1, target_x + 1);

	return 0;
}