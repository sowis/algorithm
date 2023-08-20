#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(const unsigned long long n) {
	if (n < 2) {
		return false;
	}

	const unsigned long long target = min((unsigned long long)sqrt(n) + 1, n - 1);
	for (unsigned long long i = 2; i <= target; ++i) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main(void) {
	long long T;
	scanf("%lld", &T);

	for (int i = 0; i < T; ++i) {
		long long n;
		scanf("%lld", &n);

		while (is_prime(n) == false) {
			++n;
		}

		printf("%lld\n", n);
	}

	return 0;
}