#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		result += i;
	}

	printf("%d\n", result);
	printf("%d\n", result * result);

	result = 0;
	for (int i = 1; i <= N; ++i) {
		result += i * i * i;
	}

	printf("%d\n", result);

	return 0;
}