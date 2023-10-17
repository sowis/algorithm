#include <cstdio>

int main(void) {
	long long N;
	scanf("%lld", &N);

	while (N != 1) {
		if (N % 2) {
			printf("0\n");
			return 0;
		}

		N /= 2;
	}

	printf("1\n");

	return 0;
}