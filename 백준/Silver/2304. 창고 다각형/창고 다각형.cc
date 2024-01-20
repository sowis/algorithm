#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> v(N);

	for (pair<int, int>& p : v) {
		scanf("%d%d", &p.first, &p.second);
	}

	sort(v.begin(), v.end());

	int result = 0;
	for (int i = 0; i < N; ) {
		int next_idx = -1;
		int next_max_height = -1;
		for (int k = i + 1; k < N; ++k) {
			if (v[k].second >= next_max_height) {
				next_max_height = v[k].second;
				next_idx = k;

				if (next_max_height > v[i].second) {
					break;
				}
			}
		}

		if (i == N - 1) {
			result += v[i].second;
			break;
		}

		if (next_max_height < v[i].second) {
			result += v[i].second;
			result += (v[next_idx].first - v[i].first - 1) * next_max_height;
			i = next_idx;
		}
		else {
			result += (v[next_idx].first - v[i].first) * v[i].second;
			i = next_idx;
		}
	}

	printf("%d\n", result);

	return 0;
}