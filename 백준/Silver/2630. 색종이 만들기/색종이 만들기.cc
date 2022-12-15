#include <cstdio>

using namespace std;

int paper[128][128];
int blue_count = 0;
int white_count = 0;

bool all_same_color(const int y_offset, const int x_offset, const int size) {
	const int start_color = paper[y_offset][x_offset];

	for (int i = y_offset; i < y_offset + size; ++i) {
		for (int k = x_offset; k < x_offset + size; ++k) {
			if (paper[i][k] != start_color) {
				return false;
			}
		}
	}

	return true;
}

void cut(int y_offset, int x_offset, int size) {
	if (size == 1 || all_same_color(y_offset, x_offset, size) == true) {
		if (paper[y_offset][x_offset] == 1) {
			++blue_count;
		}
		else {
			++white_count;
		}
		return;
	}

	const int half_size = size / 2;
	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 2; ++k) {
			cut(y_offset + (half_size * i), x_offset + (half_size * k), half_size);
		}
	}

	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			scanf("%d", &paper[i][k]);
		}
	}

	cut(0, 0, n);
	printf("%d\n%d", white_count, blue_count);

	return 0;
}