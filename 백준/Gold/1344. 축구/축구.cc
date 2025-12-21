#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int primes[] = { 2, 3, 5, 7, 11, 13, 17 };
vector<vector<int>> ncr(19, vector<int>(19, -1));

int nCr(const int n, const int r) {
	int& c = ncr[n][r];
	if (c != -1) {
		return c;
	}

	if (n == r || r == 0) {
		return c = 1;
	}

	return c = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main(void) {
	double p1, p2;
	cin >> p1 >> p2;
	p1 /= 100;
	p2 /= 100;

	double prime_score_p1 = 0;
	for (const int prime : primes) {
		prime_score_p1 += nCr(18, prime) * pow(p1, prime) * pow(1 - p1, 18 - prime);
	}

	double prime_score_p2 = 0;
	for (const int prime : primes) {
		prime_score_p2 += nCr(18, prime) * pow(p2, prime) * pow(1 - p2, 18 - prime);
	}

	double result = 1 - ((1 - prime_score_p1) * (1 - prime_score_p2));
	cout << fixed;
	cout.precision(10);
	cout << result;

	return 0;
}