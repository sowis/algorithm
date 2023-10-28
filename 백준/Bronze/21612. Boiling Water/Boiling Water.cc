#include <cstdio>

int main(void) {
	int b;
	scanf("%d", &b);

	printf("%d\n", b * 5 - 400);

	if (b > 100) {
		printf("-1");
	}
	else if (b < 100) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}