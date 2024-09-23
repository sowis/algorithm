#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		long long n;
		scanf("%lld", &n);

		printf("%lld\n", n * n);
	}

	return 0;
}