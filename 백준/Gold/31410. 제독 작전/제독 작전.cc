#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<pair<long long, long long>> v(N);
	for (pair<long long, long long>& p : v) {
		cin >> p.first >> p.second;
	}

	sort(v.begin(), v.end());

	long long result = numeric_limits<long long>::max();
	long long left_to_right = v[0].second;
	long long drops = 1;
	for (int i = 1; i < N; ++i) {
		left_to_right += (v[i].first - v[i - 1].first) * drops;
		++drops;
		left_to_right += v[i].second;

		if (i == N - 2) {
			result = min(result, left_to_right);
		}
	}

	for (int remove = 0; remove < N; ++remove) {
		long long current_polu = left_to_right;
		current_polu -= (v[N - 1].first - v[remove].first);
		current_polu -= v[remove].second;
		result = min(result, current_polu);
	}

	long long right_to_left = v[N - 1].second;
	drops = 1;
	for (int i = N - 2; i >= 0; --i) {
		right_to_left += (v[i + 1].first - v[i].first) * drops;
		++drops;
		right_to_left += v[i].second;

		if (i == 1) {
			result = min(result, right_to_left);
		}
	}

	for (int remove = N - 1; remove > 0; --remove) {
		long long current_polu = right_to_left;
		current_polu -= (v[remove].first - v[0].first);
		current_polu -= v[remove].second;
		result = min(result, current_polu);
	}

	cout << result;

	return 0;
}