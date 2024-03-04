#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int SOURCE = 401;
constexpr int SINK = 402;

// 1~100 -> 사람 begin
// 101~200 -> 사람 end
// 201~300 -> 서점 begin
// 301~400 -> 서점 end
int capacity[403][403];
int cost[403][403];
int flow[403][403];
vector<int> edges[403];

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	// 시작점 -> 사람 begin 잇기
	for (int people = 1; people <= N; ++people) {
		edges[SOURCE].push_back(people);
		edges[people].push_back(SOURCE);
		capacity[SOURCE][people] = INF;
	}

	// 서점 end -> 끝점 잇기
	for (int bookstore = 301; bookstore <= M + 300; ++bookstore) {
		edges[bookstore].push_back(SINK);
		edges[SINK].push_back(bookstore);
		capacity[bookstore][SINK] = INF;
	}

	// 각 사람이 몇권까지 사는지 잇기
	for (int i = 0; i < N; ++i) {
		const int people = i + 1;
		scanf("%d", &capacity[people][people + 100]);
		edges[people].push_back(people + 100);
		edges[people + 100].push_back(people);
	}

	// 서점에 책이 몇권있는지 잇기
	for (int i = 0; i < M; ++i) {
		const int bookstore = i + 201;
		scanf("%d", &capacity[bookstore][bookstore + 100]);
		edges[bookstore].push_back(bookstore + 100);
		edges[bookstore + 100].push_back(bookstore);
	}

	// 서점에서 최대 몇권 살 수 있는지 잇기
	for (int i = 0; i < M; ++i) {
		const int bookstore = i + 201;
		for (int k = 0; k < N; ++k) {
			const int people = k + 1;
			scanf("%d", &capacity[people + 100][bookstore]);
			edges[people + 100].push_back(bookstore);
			edges[bookstore].push_back(people + 100);
		}
	}

	// 배송비 잇기
	for (int i = 0; i < M; ++i) {
		const int bookstore = i + 201;
		for (int k = 0; k < N; ++k) {
			const int people = k + 1;
			int c;
			scanf("%d", &c);

			cost[people + 100][bookstore] = c;
			cost[bookstore][people + 100] = -c;
		}
	}

	int max_buy = 0;
	int min_cost = 0;

	while (true) {
		vector<int> prev(403, -1);
		vector<int> dist(403, INF);
		vector<bool> in_queue(403, false);

		queue<int> q;
		q.push(SOURCE);
		in_queue[SOURCE] = true;
		dist[SOURCE] = 0;

		while (q.empty() == false) {
			const int cur = q.front();
			q.pop();
			in_queue[cur] = false;

			for (const int next : edges[cur]) {
				if (capacity[cur][next] <= flow[cur][next]) {
					continue;
				}

				if (dist[next] <= dist[cur] + cost[cur][next]) {
					continue;
				}

				dist[next] = dist[cur] + cost[cur][next];
				prev[next] = cur;

				if (in_queue[next] == false) {
					in_queue[next] = true;
					q.push(next);
				}
			}
		}

		if (prev[SINK] == -1) {
			break;
		}

		int flow_amount = INF;
		for (int cur = SINK; prev[cur] != SOURCE; cur = prev[cur]) {
			flow_amount = min(flow_amount, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
		}

		for (int cur = SINK; prev[cur] != SOURCE; cur = prev[cur]) {
			min_cost += cost[prev[cur]][cur] * flow_amount;
			flow[prev[cur]][cur] += flow_amount;
			flow[cur][prev[cur]] -= flow_amount;
		}

		max_buy += flow_amount;
	}

	printf("%d\n", max_buy);
	printf("%d\n", min_cost);

	return 0;
}