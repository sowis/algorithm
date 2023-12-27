#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	const int result = (N * (N - 1) * (N - 2) * (N - 3)) / 24;
	printf("%d\n", result);

	return 0;
}