#include <cstdio>

long long fact[21];

int main(void) {
	fact[0] = 1;
	fact[1] = 1;

	for (int i = 2; i < 21; ++i) {
		fact[i] = i * fact[i - 1];
	}

	int N;
	scanf("%d\n", &N);

	printf("%lld\n", fact[N]);

	return 0;
}