#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		long long x, y;
		scanf("%lld%lld", &x, &y);

		printf("%lld\n", x + y);
	}

	return 0;
}