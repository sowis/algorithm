#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<bool> is_prime(100001, true);
vector<int> primes;

void test_case(void) {
	int N;
	scanf("%d", &N);

	map<int, int> result;
	int prime_index = 0;
	while (prime_index < primes.size() && is_prime[N] == false) {
		if (N % primes[prime_index] != 0) {
			++prime_index;
			continue;
		}
		
		++result[primes[prime_index]];
		N /= primes[prime_index];
	}

	++result[N];

	for (const pair<int, int>& p : result) {
		printf("%d %d\n", p.first, p.second);
	}
}

int main(void) {
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i <= sqrt(100001); ++i) {
		if (is_prime[i] == false) {
			continue;
		}

		for (int mul = 2; mul * i <= 100000; ++mul) {
			is_prime[mul * i] = false;
		}
	}

	for (int i = 2; i <= 100000; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}