#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		printf("%d ", i);

		if (i % 6 == 0) {
			printf("Go! ");
		}
	}

	if (N % 6 != 0) {
		printf("Go!\n");
	}

	return 0;
}