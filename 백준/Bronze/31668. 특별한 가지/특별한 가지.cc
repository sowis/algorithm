#include <cstdio>

using namespace std;

int main(void) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	const int result = M / N * K;
	printf("%d\n", result);

	return 0;
}