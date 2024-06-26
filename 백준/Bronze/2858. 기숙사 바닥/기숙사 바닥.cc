#include <cstdio>

int main(void) {
	int R, B;
	scanf("%d%d", &R, &B);

	for (int a = 3; a <= 5000; ++a) {
		for (int b = 3; b <= a; ++b) {
			if (2 * a + 2 * b - 4 > R) {
				break;
			}

			if (2 * a + 2 * b - 4 != R) {
				continue;
			}

			if ((a - 2) * (b - 2) > B) {
				break;
			}

			if ((a - 2) * (b - 2) != B) {
				continue;
			}

			printf("%d %d\n", a, b);
			return 0;
		}
	}

	return 0;
}