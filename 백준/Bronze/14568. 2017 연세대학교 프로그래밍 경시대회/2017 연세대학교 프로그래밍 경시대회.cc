#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int tech = 2; tech < N; tech += 2) {
		const int remain = N - tech;
		for (int nam = 1; nam < remain; ++nam) {
			const int young = remain - nam;
			if (young < nam + 2) {
				break;
			}

			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}