#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class union_find {
private:
	int N;
	vector<int> parents;

public:
	union_find(const int size)
		:N(size) {
		this->parents = vector<int>(this->N, -1);
	}

	int get_group(const int target) {
		if (this->parents[target] == -1 || this->parents[target] == target) {
			return this->parents[target] = target;
		}

		return this->parents[target] = this->get_group(this->parents[target]);
	}

	void merge(const int target_1, const int target_2) {
		const int group_1 = this->get_group(target_1);
		const int group_2 = this->get_group(target_2);

		this->parents[group_1] = group_2;
	}
};

int kruscal(const vector<vector<pair<int, int>>>& edges) {
	union_find uf((int)edges.size());
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int result = 0;

	for (const pair<int, int>& p : edges[1]) {
		pq.push({ p.second, p.first });
	}

	while (pq.empty() == false) {
		const pair<int, int> p = pq.top();
		pq.pop();

		if (uf.get_group(1) == uf.get_group(p.second)) {
			continue;
		}

		result += p.first;
		uf.merge(1, p.second);

		for (const pair<int, int>& next : edges[p.second]) {
			if (uf.get_group(1) == uf.get_group(next.first)) {
				continue;
			}

			pq.push({ next.second, next.first });
		}
	}
	
	for (int school = 1; school < edges.size(); ++school) {
		if (uf.get_group(1) != uf.get_group(school)) {
			return -1;
		}
	}

	return result;
}

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<char> colors(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> colors[i];
	}

	vector<vector<pair<int, int>>> edges(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v, d;
		cin >> u >> v >> d;

		if (colors[u] == colors[v]) {
			continue;
		}

		edges[u].push_back({ v, d });
		edges[v].push_back({ u, d });
	}

	const int result = kruscal(edges);
	cout << result << "\n";

	return 0;
}