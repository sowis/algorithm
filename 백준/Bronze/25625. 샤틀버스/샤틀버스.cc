#include <cstdio>

int main(void) {
	int x, y;
	scanf("%d%d", &x, &y);

	if (x <= y) {
		printf("%d\n", y - x);
	}
	else {
		printf("%d\n", y + x);
	}

	return 0;
}