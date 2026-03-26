#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	long long N;
	cin >> N;

	vector<long long> money(N);
	long long money_sum = 0;
	for (long long& m : money) {
		cin >> m;
		money_sum += m;
	}

	for (long long i = 0; i < N; ++i) {
		money.push_back(money[i]);
	}

	long long result = 0;
	for (long long begin = 0; begin < N; ++begin) {
		long long cur_sum = 0;
		for (long long len = 1; len < N; ++len) {
			cur_sum += money[begin + len - 1];

			if (cur_sum >= 0) {
				continue;
			}

			result += (long long)ceil((double)(-1 * cur_sum) / money_sum);
		}
	}

	cout << result;

	return 0;
}