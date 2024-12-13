#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 1;
	for (int i = 2; i <= N; ++i) {
		result *= i;
		result %= 10;
	}

	printf("%d\n", result);

	return 0;
}