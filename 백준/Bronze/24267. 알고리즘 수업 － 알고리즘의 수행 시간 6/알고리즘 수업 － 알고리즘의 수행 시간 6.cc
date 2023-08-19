#include <cstdio>
#include <vector>

using namespace std;

vector<vector<long long>> cache(500001, vector<long long>(4, -1));

long long nCr(const long long n, const long long r) {
	long long& c = cache[n][r];
	if (c != -1) {
		return c;
	}

	if (r == 0 || n == r) {
		return c = 1;
	}

	return c = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main(void) {
	long long n;
	scanf("%lld", &n);

	if (n < 3) {
		printf("0\n3\n");
		return 0;
	}

	const long long result = nCr(n, 3);

	printf("%lld\n", result);
	printf("3\n");

	return 0;
}