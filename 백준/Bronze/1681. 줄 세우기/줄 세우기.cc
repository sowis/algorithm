#include <cstdio>

bool inside(int number, const int target) {
	while (number != 0) {
		if (number % 10 == target) {
			return true;
		}

		number /= 10;
	}

	return false;
}

int main(void) {
	int N, L;
	scanf("%d%d", &N, &L);

	int result = 1;
	for (int i = 0; i < N; ++i) {
		while (inside(result, L)) {
			++result;
		}

		++result;
	}

	printf("%d\n", result - 1);

	return 0;
}