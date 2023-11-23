#include <cstdio>

int main(void) {
	int c, k, p;
	scanf("%d%d%d", &c, &k, &p);

	int result = 0;
	for (int i = 1; i <= c; ++i) {
		result += (k * i + p * i * i);
	}

	printf("%d\n", result);

	return 0;
}