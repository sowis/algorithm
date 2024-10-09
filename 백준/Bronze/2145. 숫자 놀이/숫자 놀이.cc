#include <cstdio>

int main(void) {
	while (true) {
		int N;
		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		int cur = N;
		while (cur >= 10) {
			int next = 0;
			while (cur != 0) {
				next += cur % 10;
				cur /= 10;
			}

			cur = next;
		}

		printf("%d\n", cur);
	}

	return 0;
}