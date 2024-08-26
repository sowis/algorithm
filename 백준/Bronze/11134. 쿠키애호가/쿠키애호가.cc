#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N, C;
		scanf("%d%d", &N, &C);

		if (N % C) {
			printf("%d\n", N / C + 1);
		}
		else {
			printf("%d\n", N / C);
		}
	}

	return 0;
}