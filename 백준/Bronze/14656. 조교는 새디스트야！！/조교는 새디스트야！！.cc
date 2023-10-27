#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int idx = 1;
	int result = 0;

	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		if (input != idx) {
			++result;
		}

		++idx;
	}

	printf("%d\n", result);

	return 0;
}