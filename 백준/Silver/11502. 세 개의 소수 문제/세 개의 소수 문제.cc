#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> numbers(1001, true);

void solve(const vector<int>& primes) {
	int K;
	scanf("%d", &K);

	for (const int a : primes) {
		if (a + 4 > K) {
			break;
		}

		for (const int b : primes) {
			if (a + b + 2 > K) {
				break;
			}

			const int remain = K - a - b;
			if (numbers[remain]) {
				printf("%d %d %d\n", a, b, remain);
				return;
			}
		}
	}

	printf("0\n");
}

int main(void) {
	for (int i = 2; i < 1001; ++i) {
		if (numbers[i] == false) {
			continue;
		}

		for (int mul = 2; i * mul < 1001; ++mul) {
			numbers[i * mul] = false;
		}
	}

	vector<int> primes;

	for (int i = 2; i < 1001; ++i) {
		if (numbers[i] == false) {
			continue;
		}

		primes.push_back(i);
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		solve(primes);
	}

	return 0;
}