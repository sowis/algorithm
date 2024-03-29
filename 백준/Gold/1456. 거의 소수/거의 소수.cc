#include <cstdio>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<bool> primes(10000001, true);

int main(void) {
	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i < 3165; ++i) {
		if (primes[i] == false) {
			continue;
		}

		for (int mul = 2; mul * i < 10000001; ++mul) {
			primes[mul * i] = false;
		}
	}

	long long A, B;
	scanf("%lld%lld", &A, &B);

	unordered_set<long long> results;
	long long N = 2;
	while (true) {
		const long long left = (long long)floor(pow((double)A, 1.0 / N));
		const long long right = (long long)floor(pow((double)B, 1.0 / N));

		if (left == 1 && right == 1) {
			break;
		}

		for (long long i = left; i <= right + 1; ++i) {
			if (primes[i] == false) {
				continue;
			}

			const long long p = (long long)pow(i, N);
			if (p < A) {
				continue;
			}

			if (B < p) {
				break;
			}

			results.insert((long long)pow(i, N));
		}

		++N;
	}

	printf("%zd\n", results.size());

	return 0;
}