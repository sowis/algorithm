#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a >= b) {
			printf("MMM BRAINS\n");
		}
		else {
			printf("NO BRAINS\n");
		}
	}

	return 0;
}