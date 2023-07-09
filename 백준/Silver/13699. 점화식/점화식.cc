#include <cstdio>
#include <vector>

using namespace std;

vector<long long> cache(36, -1);

long long foo(const int n) {
	long long& c = cache[n];
	if (c != -1) {
		return c;
	}

	long long result = 0;
	for (int i = 0; i < n; ++i) {
		result += foo(i) * foo(n - i - 1);
	}

	return c = result;
}

int main(void) {
	cache[0] = 1;

	int N;
	scanf("%d", &N);

	const long long result = foo(N);

	printf("%lld\n", result);

	return 0;
}