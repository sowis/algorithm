#include <cstdio>
#include <vector>

using namespace std;

vector<vector<long long>> cache(40, vector<long long>(40, -1));

long long nCr(const int n, const int r) {
	long long& c = cache[n][r];
	if (c != -1) {
		return c;
	}

	if (r == 0 || n == r) {
		return c = 1;
	}

	return c = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	const long long result = nCr(N - 1, K - 1);

	printf("%lld\n", result);

	return 0;
}