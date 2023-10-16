#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	long long result = 0;
	for (int lo = 1; lo <= N; ++lo) {
		for (int up = 0; up <= lo; ++up) {
			result += lo;
			result += up;
		}
	}

	printf("%lld\n", result);

	return 0;
}