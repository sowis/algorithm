#include <cstdio>

int main(void) {
	int h, i, a, r, c;
	scanf("%d%d%d%d%d", &h, &i, &a, &r, &c);

	const int result = (h * i) - (a * r * c);
	printf("%d\n", result);

	return 0;
}