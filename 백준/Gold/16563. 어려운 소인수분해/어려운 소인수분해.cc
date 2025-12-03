#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int prime_max = 5000001;

vector<int> min_prime_factors;

int main(void) {
	ios_base::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);

	min_prime_factors = vector<int>(prime_max, -1);

	for (int i = 0; i < prime_max; ++i) {
		min_prime_factors[i] = i;
	}

	const int sqt = (int)sqrt(prime_max);

	for (int base = 2; base <= sqt; ++base) {
		for (int mul = 2; base * mul < prime_max; ++mul) {
			if (min_prime_factors[base * mul] == base * mul) {
				min_prime_factors[base * mul] = base;
			}
		}
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int K;
		cin >> K;

		bool first = true;
		while (1 < K) {
			if (first == false) {
				cout << ' ';
			}

			first = false;
			cout << min_prime_factors[K];
			K /= min_prime_factors[K];
		}

		cout << '\n';
	}

	return 0;
}