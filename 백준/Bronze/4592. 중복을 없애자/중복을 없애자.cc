#include <cstdio>

int main(void) {
	while (true) {
		int N;
		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		int last = -1;
		for (int i = 0; i < N; ++i) {
			int cur;
			scanf("%d", &cur);

			if (cur == last) {
				continue;
			}

			printf("%d ", cur);
			last = cur;
		}

		printf("$\n");
	}

	return 0;
}