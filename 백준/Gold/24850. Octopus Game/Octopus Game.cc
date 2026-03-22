#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	long long a, b;
	cin >> a >> b;

	vector<pair<long long, long long>> results;

	while (a != 0 && b != 0) {
		if (abs(a) > abs(b)) {
			long long k = -1 * (a / b);
			long long min_remain = a + (b * k);
			for (long long candidate_k = -1 * (a / b) - 1; candidate_k < -1 * (a / b) + 2; ++candidate_k) {
				if (abs(min_remain) > abs(a + (b * candidate_k))) {
					min_remain = a + (b * candidate_k);
					k = candidate_k;
				}
			}

			results.push_back({ 1, k });
			a = a + (b * k);
		}
		else {
			long long k = -1 * (b / a);
			long long min_remain = b + (a * k);
			for (long long candidate_k = -1 * (b / a) - 1; candidate_k < -1 * (b / a) + 2; ++candidate_k) {
				if (abs(min_remain) > abs(b + (a * candidate_k))) {
					min_remain = b + (a * candidate_k);
					k = candidate_k;
				}
			}

			results.push_back({ 2, k });
			b = b + (a * k);
		}
	}

	cout << results.size() << "\n";
	for (const pair<long long, long long>& p : results) {
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}