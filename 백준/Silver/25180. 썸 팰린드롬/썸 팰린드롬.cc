#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

long long solve(const long long N) {
	long long result = numeric_limits<long long>::max();
	if ((N % 2) == 0) {
		result = min(result, 2 * (1 + (((N - 1) / 2) / 9)));
	}

	for (int i = 1; i <= 9; ++i) {
		const long long new_N = N - i;
		if (new_N % 2) {
			continue;
		}

		result = min(result, 1 + 2 * (1 + (((new_N - 1) / 2) / 9)));
	}

	return result;
}

int main(void) {
	long long N;
	cin >> N;

	if (N < 10) {
		cout << 1;
		return 0;
	}

	cout << solve(N);

	return 0;
}