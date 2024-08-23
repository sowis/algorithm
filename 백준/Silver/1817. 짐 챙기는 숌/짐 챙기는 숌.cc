#include <cstdio>

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int result = 0;
	int weight = 0;

	for (int i = 0; i < N; ++i) {
		int w;
		scanf("%d", &w);

		if (weight + w > M) {
			++result;
			weight = w;
		}
		else {
			weight += w;
		}
	}

	if (weight > 0) {
		++result;
	}

	printf("%d\n", result);

	return 0;
}