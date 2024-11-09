#include <cstdio>

int main(void) {
	int x, N;
	scanf("%d%d", &x, &N);

	for (int i = 0; i < N; ++i) {
		if (x % 2) {
			x = (2 * x) ^ 6;
		}
		else {
			x = (x / 2) ^ 6;
		}
	}

	printf("%d\n", x);

	return 0;
}