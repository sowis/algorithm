#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(100, vector<long long>(100, -1));

long long nCr(const long long n, const long long r) {
	long long& c = cache[n][r];
	if (c != -1) {
		return c;
	}

	if (r == 0) {
		return c = 1;
	}

	if (n == r) {
		return c = 1;
	}

	return c = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main(void) {
	long long N, M;
	cin >> N >> M;

	const long long n = M - 1;
	const long long r = M - N;

	const long long result = nCr(n, r);
	cout << result;

	return 0;
}