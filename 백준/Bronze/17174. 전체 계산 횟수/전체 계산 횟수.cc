#include <cstdio>

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int result = 0;
	while (N > 0) {
		result += N;
		N /= M;
	}

	printf("%d\n", result);

	return 0;
}