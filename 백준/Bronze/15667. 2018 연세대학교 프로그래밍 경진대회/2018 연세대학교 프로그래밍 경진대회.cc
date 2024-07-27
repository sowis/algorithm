#include <cstdio>

int main(void) {
	int target;
	scanf("%d", &target);

	for (int i = 1; ; ++i) {
		if (1 + i + i * i == target) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}