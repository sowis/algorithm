#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct _data {
	int city;
	int distance;

	bool operator< (const struct _data& d) const {
		return this->distance > d.distance;
	}
} Data;

unordered_map<int, unordered_set<int>> edges;
vector<int> distances;

int main(void) {
	int N, M, K, X;
	scanf("%d%d%d%d", &N, &M, &K, &X);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edges[a].insert(b);
	}

	distances = vector<int>(N + 1, numeric_limits<int>::max());
	priority_queue<Data> q;

	distances[X] = 0;
	q.push({ X, 0 });

	while (!q.empty()) {
		const Data d = q.top();
		q.pop();

		if (distances[d.city] < d.distance) {
			continue;
		}

		const int next_distance = d.distance + 1;
		for (const int next : edges[d.city]) {
			if (distances[next] <= next_distance) {
				continue;
			}

			distances[next] = next_distance;
			q.push({ next, next_distance });
		}
	}

	vector<int> results;
	for (int city = 1; city <= N; ++city) {
		if (distances[city] == K) {
			results.push_back(city);
		}
	}

	if (results.empty()) {
		printf("-1\n");
		return 0;
	}

	sort(results.begin(), results.end());

	for (const int result : results) {
		printf("%d\n", result);
	}

	return 0;
}
