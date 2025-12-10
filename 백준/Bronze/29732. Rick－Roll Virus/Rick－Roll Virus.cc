#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<bool> next_day(N);
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;

		if (c == '.') {
			continue;
		}

		const int left = max(0, i - K);
		const int right = min(N - 1, i + K);

		for (int i = left; i <= right; ++i) {
			next_day[i] = true;
		}
	}

	int infest = 0;
	for (const int is_infest : next_day) {
		if (is_infest) {
			++infest;
		}
	}

	if (infest <= M) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}