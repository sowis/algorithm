#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		long long N;
		scanf("%lld", &N);

		long long cur = 0;
		for (int k = 0; k < 6; ++k) {
			int tmp;
			scanf("%d", &tmp);

			cur += tmp;
		}

		int result = 1;
		while (cur <= N) {
			++result;
			cur *= 4;
		}

		printf("%d\n", result);
	}

	return 0;
}