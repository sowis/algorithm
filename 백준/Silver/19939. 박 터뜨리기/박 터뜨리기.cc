#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	if (N < (K * (K + 1)) / 2) {
		printf("-1\n");
		return 0;
	}

	N -= (K * (K + 1)) / 2;
	N %= K;

	int result = K - 1;
	if (N % K) {
		++result;
	}

	printf("%d\n", result);

	return 0;
}