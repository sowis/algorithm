#include <cstdio>
#include <vector>

using namespace std;

int solve(const long long N) {
	int result = 1;
	long long upper = 1;
	while (upper < N) {
		++result;
		upper *= 2;
	}

	return result;
}

int main(void) {
	long long N;
	scanf("%lld", &N);

	if (N == 0) {
		printf("0\n");
	}
	else {
		printf("%d\n", solve(N));
	}

	return 0;
}