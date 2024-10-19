#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	K += 60;

	const int in = min(N, K);
	const int out = max(0, N - in);

	const int result = in * 1500 + out * 3000;
	printf("%d\n", result);

	return 0;
}