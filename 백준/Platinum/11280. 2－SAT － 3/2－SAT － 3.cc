#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

constexpr int NO_ID = 0;

int N, M;
vector<vector<int>> edges;
vector<vector<int>> rev_edges;

// 1 ~ N: original, N+1 ~ 2*N: reversed
inline int rev(const int node) {
	return node + ((node <= N) ? N : -N);
}

void dfs(stack<int>& stk, const int current, vector<bool>& visit) {
	visit[current] = true;

	for (const int next : edges[current]) {
		if (visit[next]) {
			continue;
		}

		dfs(stk, next, visit);
	}

	stk.push(current);
}

void rev_dfs(const int current, const int id, vector<int> &scc_ids) {
	scc_ids[current] = id;

	for (const int next : rev_edges[current]) {
		if (scc_ids[next] != NO_ID) {
			continue;
		}

		rev_dfs(next, id, scc_ids);
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	edges = vector<vector<int>>(2 * N + 1);
	rev_edges = vector<vector<int>>(2 * N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a < 0) {
			a *= -1;
			a += N;
		}

		if (b < 0) {
			b *= -1;
			b += N;
		}

		edges[rev(a)].push_back(b);
		edges[rev(b)].push_back(a);
		rev_edges[b].push_back(rev(a));
		rev_edges[a].push_back(rev(b));
	}

	for (vector<int>& v : edges) {
		sort(v.begin(), v.end());
	}

	/* scc 구하기 (코사라주 알고리즘) */
	stack<int> stk;
	vector<bool> visit(2 * N + 1, false);
	for (int target = 1; target <= 2 * N; ++target) {
		if (visit[target]) {
			continue;
		}

		dfs(stk, target, visit);
	}

	int scc_id_generator = 1;
	vector<int> scc_ids(2 * N + 1, NO_ID);

	while (stk.empty() == false) {
		const int target = stk.top();
		stk.pop();
		
		if (scc_ids[target] != NO_ID) {
			continue;
		}

		rev_dfs(target, scc_id_generator, scc_ids);
		++scc_id_generator;
	}
	/***********************************/

	for (int node = 1; node <= N; ++node) {
		if (scc_ids[node] == scc_ids[rev(node)]) {
			printf("0\n");
			return 0;
		}
	}

	printf("1\n");

	return 0;
}