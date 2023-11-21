#include <cstdio>

int main(void) {
	int N, T;
	scanf("%d%d", &N, &T);

	int count = 0;
	int cur = 0;
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);

		if (cur + n > T) {
			break;
		}

		cur += n;
		++count;
	}

	printf("%d\n", count);

	return 0;
}