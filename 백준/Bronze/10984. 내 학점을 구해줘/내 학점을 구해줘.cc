#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int count = 0;
		double grade_sum = 0;

		int N;
		scanf("%d", &N);

		for (int k = 0; k < N; ++k) {
			int a;
			double b;
			scanf("%d%lf", &a, &b);

			count += a;
			grade_sum += a * b;
		}

		printf("%d %.1lf\n", count, grade_sum / count);
	}

	return 0;
}