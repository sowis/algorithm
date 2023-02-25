#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<unsigned long long>> cache(201, vector<unsigned long long>(101, -1));

unsigned long long nCr(const unsigned long long n, const unsigned long long r) {
	unsigned long long& c = cache[n][r];
	if (c != -1) {
		return c;
	}

	if (n == r) {
		return c = 1;
	}

	if (r == 0) {
		return c = 1;
	}

	return c = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

string solve(unsigned long long N, unsigned long long M, unsigned long long K) {
	if (K > nCr(N + M, N)) {
		return "-1";
	}

	string result = "";

	while (N > 0 && M > 0) {
		if (nCr(N + M - 1, N - 1) < K) {
			result += 'z';
			K -= nCr(N + M - 1, N - 1);
			--M;
		}
		else {
			result += 'a';
			--N;
		}
	}

	while (N > 0) {
		result += 'a';
		--N;
	}

	while (M > 0) {
		result += 'z';
		--M;
	}

	return result;
}

int main(void) {
	unsigned long long N, M, K;
	cin >> N >> M >> K;

	cout << solve(N, M, K);

	return 0;
}