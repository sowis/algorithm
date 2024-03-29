#include <cstdio>

constexpr bool repeat[7] = { true, false, true, true, true, true, false };

int main(void) {
	long long N;
	scanf("%lld", &N);
	
	--N;
	N %= 7;

	printf("%s\n", repeat[N] ? "SK" : "CY");

	return 0;
}