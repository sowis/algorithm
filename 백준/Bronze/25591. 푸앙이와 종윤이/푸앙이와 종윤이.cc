#include <cstdio>

int main(void) {
	int n1, n2;
	scanf("%d%d", &n1, &n2);

	const int a = 100 - n1;
	const int b = 100 - n2;

	const int c = 100 - (a + b);
	const int d = a * b;

	const int q = d / 100;
	const int r = d % 100;

	printf("%d %d %d %d %d %d\n", a, b, c, d, q, r);
	printf("%d %d\n", c + q, r);

	return 0;
}