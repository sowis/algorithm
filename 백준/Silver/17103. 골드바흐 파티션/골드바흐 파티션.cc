#include <cstdio>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<bool> is_prime(1000001, true);
unordered_set<int> primes;
vector<int> primes_v;

void test_case(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (const int prime : primes_v) {
		if (prime >= N) {
			break;
		}

		if (primes.find(N - prime) != primes.end()) {
			++result;

			if (N - prime == prime) {
				++result;
			}
		}
	}

	result /= 2;
	printf("%d\n", result);
}

int main(void) {
	is_prime[0] = false;
	is_prime[1] = false;

	const int sqrt_1000001 = (int)sqrt(1000001) + 1;
	for (int root = 0; root < sqrt_1000001; ++root) {
		if (is_prime[root] == false) {
			continue;
		}

		for (int mul = 2; root * mul < 1000001; ++mul) {
			is_prime[root * mul] = false;
		}
	}

	for (int i = 2; i < 1000001; ++i) {
		if (is_prime[i]) {
			primes.insert(i);
			primes_v.push_back(i);
		}
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}