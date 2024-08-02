#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int a = 1; a <= 500; ++a) {
		for (int b = 1; b <= a; ++b) {
			if (a * a == b * b + N) {
				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}