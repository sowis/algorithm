#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	unordered_map<int, vector<int>> m;

	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);

		m[y].push_back(x);
	}

	int result = 0;
	for (const pair<int, vector<int>>& p : m) {
		vector<int> v = p.second;
		sort(v.begin(), v.end());

		int min_dist = 987654321;
		int cur = v[0];
		for (int i = 1; i < v.size(); ++i) {
			min_dist = min(min_dist, v[i] - cur);
			cur = v[i];
		}

		result += v[v.size() - 1] - v[0] + min_dist;
	}

	printf("%d\n", result);

	return 0;
}