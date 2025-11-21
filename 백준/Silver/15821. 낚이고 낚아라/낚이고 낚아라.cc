#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<long long> effective_distances_2;
	for (int line = 0; line < N; ++line) {
		int p;
		cin >> p;

		long long max_dist_2 = 0;
		for (int i = 0; i < p; ++i) {
			long long y, x;
			cin >> y >> x;
			max_dist_2 = max(max_dist_2, y * y + x * x);
		}

		effective_distances_2.push_back(max_dist_2);
	}

	sort(effective_distances_2.begin(), effective_distances_2.end());

	cout << effective_distances_2[K - 1] << ".00\n";

	return 0;
}