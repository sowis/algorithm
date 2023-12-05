#include <cstdio>

using namespace std;

int main(void) {
	long long N;
	scanf("%lld", &N);

	long long result = 1;
	for (int i = 1; i <= N; ++i) {
		result *= i;
	}

	printf("%lld\n", result / 604800);

	return 0;
}