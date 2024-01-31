#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef struct _path {
	int begin;
	int end;
	int speed;

	bool operator<(const _path& p) const {
		if (this->begin != p.begin) {
			return this->begin < p.begin;
		}

		return this->end < p.end;
	}
} Path;

int main(void) {
	int N, D;
	scanf("%d%d", &N, &D);

	unordered_map<int, unordered_map<int, int>> paths;
	for (int i = 0; i < N; ++i) {
		int begin, end, speed;
		scanf("%d%d%d", &begin, &end, &speed);

		if (begin < 0 || end > D) {
			continue;
		}

		if (end - begin <= speed) {
			continue;
		}

		if (paths[begin].find(end) == paths[begin].end()) {
			paths[begin][end] = speed;
		}
		else {
			paths[begin][end] = min(paths[begin][end], speed);
		}
	}

	vector<Path> v;
	for (const pair<int, unordered_map<int, int>>& p : paths) {
		const int begin = p.first;
		for (const pair<int, int>& p2 : p.second) {
			const int end = p2.first;
			const int speed = p2.second;

			v.push_back({ begin, end, speed });
		}
	}

	sort(v.begin(), v.end());

	vector<int> dist(D + 1, 987654321);
	dist[0] = 0;

	int v_idx = 0;
	for (int cur = 0; cur < D; ++cur) {		
		while (v_idx < v.size() && v[v_idx].begin == cur) {
			dist[v[v_idx].end] = min(dist[v[v_idx].end], dist[cur] + v[v_idx].speed);
			++v_idx;
		}

		dist[cur + 1] = min(dist[cur + 1], dist[cur] + 1);
	}

	printf("%d\n", dist[D]);

	return 0;
}