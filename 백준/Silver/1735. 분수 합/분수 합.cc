#include <cstdio>

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main(void) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	int up = a * d + b * c;
	int down = b * d;

	const int div = gcd(up, down);

	up /= div;
	down /= div;

	printf("%d %d", up, down);

	return 0;
}