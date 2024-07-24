#include <cstdio>

int next(const int num) {
	if (num % 2) {
		return 3 * num + 1;
	}
	else {
		return num / 2;
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 1;
	while (N != 1) {
		++result;
		N = next(N);
	}

	printf("%d\n", result);

	return 0;
}