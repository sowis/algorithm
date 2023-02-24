#include <cstdio>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long city;
	long long pave;
	long long dist;

	bool operator<(const _data& d) const {
		return this->dist > d.dist;
	}
} Data;

long long N, M, K;
vector<vector<pair<long long, long long>>> edges;
vector<vector<long long>> min_distance; // [도시][포장 횟수] = 거리

int main(void) {
	scanf("%lld%lld%lld", &N, &M, &K);

	min_distance = vector<vector<long long>>(N + 1, vector<long long>(K + 1, numeric_limits<long long>::max()));
	edges = vector<vector<pair<long long, long long>>>(N + 1);

	for (long long i = 0; i < M; ++i) {
		long long a, b, dist;
		scanf("%lld%lld%lld", &a, &b, &dist);

		edges[a].push_back({ b, dist });
		edges[b].push_back({ a, dist });
	}

	priority_queue<Data> q;
	q.push({ 1, 0, 0 });
	min_distance[1][0] = 0;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.dist > min_distance[d.city][d.pave]) {
			continue;
		}
		
		for (const pair<long long, long long>& edge : edges[d.city]) {
			const long long next_city = edge.first;
			const long long next_dist = d.dist + edge.second;

			if (min_distance[next_city][d.pave] > next_dist) {
				min_distance[next_city][d.pave] = next_dist;
				q.push({ next_city, d.pave, next_dist });
			}

			if (d.pave < K && min_distance[next_city][d.pave + 1] > d.dist) {
				min_distance[next_city][d.pave + 1] = d.dist;
				q.push({ next_city, d.pave + 1,  d.dist });
			}
		}
	}

	long long result = numeric_limits<long long>::max();
	for (long long pave = 0; pave <= K; ++pave) {
		result = min(result, min_distance[N][pave]);
	}

	printf("%lld\n", result);

	return 0;
}