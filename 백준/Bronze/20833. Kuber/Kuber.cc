#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	long long result = 0;
	for (int i = 1; i <= N; ++i) {
		result += i * i * i;
	}

	printf("%lld\n", result);

	return 0;
}