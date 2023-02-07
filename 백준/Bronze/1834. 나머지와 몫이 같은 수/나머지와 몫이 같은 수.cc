#include <cstdio>

using namespace std;

int main(void) {
	unsigned long long N;
	scanf("%lld", &N);

	const unsigned long long result = ((N * (N - 1)) / 2) * (N + 1);
	printf("%llu\n", result);

	return 0;
}