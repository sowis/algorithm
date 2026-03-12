#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	while (true) {
		unsigned long long n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}

		const unsigned long long min_value = min(n, m);
		unsigned long long result = 1;
		for (unsigned long long i = 1; i <= min_value; ++i) {
			result *= (n + m - i + 1);
			result /= i;
		}

		cout << result << "\n";
	}

	return 0;
}