#include <cstdio>

using namespace std;

unsigned long long miller_number[] = {2, 3, 5, 7, 11, 61};

// a^b mod m
unsigned long long power(unsigned long long a, const unsigned long long b, const unsigned long long m = 1) {
	a %= m;

	if (b == 1) {
		return a;
	}

	const unsigned long long half = power(a, b / 2, m);
	if (b % 2) {
		return (((half * half) % m) * a) % m;
	}

	return (half * half) % m;
}

bool miller(const unsigned long long n, const unsigned long long a) {
	if (a % n == 0) {
		return false;
	}

	unsigned long long k = n - 1;
	while (k > 0) {
		const unsigned long long cur = power(a, k, n);

		if (cur == n - 1) {
			return true;
		}

		if (k % 2) {
			return (cur == 1 || cur == n - 1);
		}

		k /= 2;
	}

	return false;
}

bool is_prime(const unsigned long long number) {
	if (number <= 1) {
		return false;
	}

	if (number == 2 || number == 3) {
		return true;
	}

	if (number % 2 == 0) {
		return false;
	}

	for (const unsigned long long base : miller_number) {
		if (number == base) {
			return true;
		}

		if (miller(number, base) == false) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int N;
	scanf("%d", &N);

	int prime_count = 0;
	for (int i = 0; i < N; ++i) {
		unsigned long long width;
		scanf("%lld", &width);

		const unsigned long long prime_candidate = 2 * width + 1;
		if (is_prime(prime_candidate)) {
			++prime_count;
		}
	}

	printf("%d\n", prime_count);

	return 0;
}