#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	N /= 3;

	int result = 0;
	for (int a = 1; a <= N - 2; ++a) {
		for (int b = 1; a + b <= N - 1; ++b) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}