#include <cstdio>

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a == b && b == c) {
		printf("*\n");
		return 0;
	}

	if (a == b) {
		printf("C\n");
	}
	else if (a == c) {
		printf("B\n");
	}
	else {
		printf("A\n");
	}

	return 0;
}