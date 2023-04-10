#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;

void print_mat(const vector<vector<int>>& arr) {
	for (int y = 0; y < arr.size(); ++y) {
		for (int x = 0; x < arr[0].size(); ++x) {
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void rotate_mat(vector<vector<int>>& arr, const int begin_y, const int begin_x, const int y_size, const int x_size, const int count) {
	for (int r = 0; r < count; ++r) {
		const int begin = arr[begin_y][begin_x];

		for (int x = begin_x; x < begin_x + x_size - 1; ++x) {
			arr[begin_y][x] = arr[begin_x][x + 1];
		}

		for (int y = begin_y; y < begin_y + y_size - 1; ++y) {
			arr[y][begin_x + x_size - 1] = arr[y + 1][begin_x + x_size - 1];
		}

		for (int x = begin_x + x_size - 1; x > begin_x; --x) {
			arr[begin_y + y_size - 1][x] = arr[begin_y + y_size - 1][x - 1];
		}

		for (int y = begin_y + y_size - 1; y > begin_y; --y) {
			arr[y][begin_x] = arr[y - 1][begin_x];
		}

		if (y_size > 1) {
			arr[begin_y + 1][begin_x] = begin;
		}
	}
}

void rotate_mat(vector<vector<int>>& arr, const int count) {
	int y_size = N;
	int x_size = M;
	int begin_y = 0;
	int begin_x = 0;

	while (min(y_size, x_size) >= 1) {
		rotate_mat(arr, begin_y, begin_x, y_size, x_size, count);
		++begin_y;
		++begin_x;
		y_size -= 2;
		x_size -= 2;
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &R);

	vector<vector<int>> arr(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &arr[y][x]);
		}
	}

	rotate_mat(arr, R);

	print_mat(arr);

	return 0;
}