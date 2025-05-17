#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int city_1;
	int city_2;
	int cost;

	bool operator< (const struct _data& d) const {
		return this->cost > d.cost;
	}
} Data;

vector<bool> is_power;
vector<int> powers;
vector<vector<pair<int, int>>> edges;
vector<int> union_find;

int uf_head(const int target, vector<int> &union_find) {
	if (union_find[target] == -1 || union_find[target] == target) {
		return union_find[target] = target;
	}

	return union_find[target] = uf_head(union_find[target], union_find);
}

void uf_merge(const int target_1, const int target_2, vector<int>& union_find) {
	const int head_1 = uf_head(target_1, union_find);
	const int head_2 = uf_head(target_2, union_find);

	union_find[head_1] = head_2;
}

int main(void) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	is_power = vector<bool>(N + 1, false);
	powers;
	for (int i = 0; i < K; ++i) {
		int power;
		scanf("%d", &power);

		is_power[power] = true;
		powers.push_back(power);
	}

	edges = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		edges[u].push_back({ v, w });
		edges[v].push_back({ u, w });
	}

	union_find = vector<int>(N + 1, -1);
	priority_queue<Data> pq;
	vector<Data> results;

	for (const int power : powers) {
		for (const pair<int, int>& p : edges[power]) {
			pq.push({ power, p.first, p.second });
		}
	}

	while (pq.empty() == false) {
		const Data d = pq.top();
		pq.pop();

		const int head_1 = uf_head(d.city_1, union_find);
		const int head_2 = uf_head(d.city_2, union_find);

		if (head_1 == head_2) {
			continue;
		}

		if (is_power[head_1] && is_power[head_2]) {
			continue;
		}

		if (is_power[head_1]) {
			uf_merge(head_2, head_1, union_find);
		}
		else {
			uf_merge(head_1, head_2, union_find);
		}

		results.push_back(d);
		for (const pair<int, int>& p : edges[d.city_2]) {
			if (union_find[p.first] != -1) {
				continue;
			}

			pq.push({ d.city_2, p.first, p.second });
		}
	}

	int result = 0;
	for (const Data& d : results) {
		result += d.cost;
	}

	printf("%d\n", result);

	return 0;
}