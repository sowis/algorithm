#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int width = 1; width <= N; ++width) {
		for (int height = width; width * height <= N; ++height) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}