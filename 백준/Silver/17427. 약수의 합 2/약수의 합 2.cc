#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	long long result = 0;
	for (int cur = 1; cur <= N; ++cur) {
		const int count = N / cur;
		result += cur * count;
	}

	printf("%lld\n", result);

	return 0;
}