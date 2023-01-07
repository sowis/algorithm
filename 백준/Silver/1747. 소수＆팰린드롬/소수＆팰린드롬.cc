#include <cstdio>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

constexpr int PRIME_MAX = 1003002;

vector<bool> primes(PRIME_MAX, true);

bool is_palindrom(const int number) {
	const string num_str = to_string(number);
	int left = 0;
	int right = (int)num_str.size() - 1;

	while (left < right) {
		if (num_str[left] != num_str[right]) {
			return false;
		}

		++left;
		--right;
	}

	return true;
}

int main(void) {
	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i < sqrt(PRIME_MAX) + 1; ++i) {
		if (primes[i] == false) {
			continue;
		}

		for (int mul = 2; i * mul < PRIME_MAX; ++mul) {
			primes[i * mul] = false;
		}
	}

	int N;
	scanf("%d", &N);

	for (int i = N; ; ++i) {
		if (primes[i] && is_palindrom(i)) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}