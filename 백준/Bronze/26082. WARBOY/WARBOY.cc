#include <cstdio>

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	const int result = (b / a) * c * 3;
	printf("%d\n", result);

	return 0;
}