#include <iostream>
#include <vector>

using namespace std;

long long nCr(const long long n, long long r) {
	if (n == r || r == 0) {
		return 1;
	}

	if (r > n - r) {
		r = n - r;
	}

	long long result = 1;
	for (int i = 1; i <= r; ++i) {
		result = result * (n + 1 - i) / i;
	}

	return result;
}

int main(void) {
	while (true) {
		int n, k;
		cin >> n >> k;

		if (n == 0 && k == 0) {
			break;
		}

		cout << nCr(n, k) << "\n";
	}

	return 0;
}