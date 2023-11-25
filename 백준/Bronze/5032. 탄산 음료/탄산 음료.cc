#include <cstdio>

int main(void) {
	int e, f, c;
	scanf("%d%d%d", &e, &f, &c);

	int result = 0;
	int empty = e + f;

	while (empty / c) {
		result += empty / c;
		empty = (empty / c) + (empty % c);
	}

	printf("%d\n", result);

	return 0;
}