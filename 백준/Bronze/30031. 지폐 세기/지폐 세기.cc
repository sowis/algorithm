#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a == 136) {
			result += 1000;
		}
		else if (a == 142) {
			result += 5000;
		}
		else if (a == 148) {
			result += 10000;
		}
		else if (a == 154) {
			result += 50000;
		}
	}

	printf("%d\n", result);

	return 0;
}