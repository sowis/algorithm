#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<long long>A(N);
	for (long long& a : A) {
		cin >> a;
	}

	sort(A.begin(), A.end(), greater<long long>());

	int a_idx = 0;
	long long current_quality = 0;
	long long last_day = 0;
	for (int i = 0; i < M; ++i) {
		long long day, target;
		cin >> day >> target;
		last_day = day;

		while ((current_quality < target) && (a_idx < N)) {
			current_quality += (A[a_idx] + day);
			++a_idx;
		}

		if ((current_quality < target) && (a_idx == N)) {
			cout << -1 << "\n";
			return 0;
		}
	}

	while (a_idx < N) {
		current_quality += (A[a_idx] + last_day);
		++a_idx;
	}

	cout << current_quality;

	return 0;
}