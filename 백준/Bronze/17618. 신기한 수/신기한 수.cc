#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;

	for (int target = 1; target <= N; ++target) {
		int sum = 0;
		int cur = target;

		while (cur != 0) {
			sum += cur % 10;
			cur /= 10;
		}

		if (target % sum == 0) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}