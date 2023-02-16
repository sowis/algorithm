#include <cstdio>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<bool> numbers(1000001, true);
unordered_set<int> primes;
vector<int> prime_vector;

int main(void) {
	for (int i = 2; i <= sqrt(1000001); ++i) {
		if (numbers[i] == false) {
			continue;
		}

		for (int mul = 2; i * mul < 1000001; ++mul) {
			numbers[i * mul] = false;
		}
	}

	for (int i = 3; i < 1000001; ++i) {
		if (numbers[i]) {
			primes.insert(i);
			prime_vector.push_back(i);
		}
	}

	int N;
	while (true) {
		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		bool exist = false;
		for (const int prime : prime_vector) {
			if (prime >= N) {
				break;
			}

			if (primes.find(N - prime) == primes.end()) {
				continue;
			}

			exist = true;
			printf("%d = %d + %d\n", N, prime, N - prime);
			break;
		}

		if (exist == false) {
			printf("Goldbach's conjecture is wrong.");
		}
	}

	return 0;
}