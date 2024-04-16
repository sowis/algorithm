#include <iostream>
#include <vector>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;
	vector<int> lazy;

	void init(const vector<int>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
	}

	void lazy_propagation(const int begin, const int end, const int idx) {
		this->arr[idx] += this->lazy[idx];

		if (end - begin == 1) {
			this->lazy[idx] = 0;
			return;
		}

		this->lazy[idx * 2] += this->lazy[idx];
		this->lazy[idx * 2 + 1] += this->lazy[idx];
		this->lazy[idx] = 0;
	}

	void update(const int target_begin, const int target_end, const int value, const int begin, const int end, const int idx) {
		this->lazy_propagation(begin, end, idx);

		if (target_end <= begin || end <= target_begin) {
			return;
		}

		if (target_begin <= begin && end <= target_end) {
			this->lazy[idx] += value;
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target_begin, target_end, value, begin, mid, idx * 2);
		this->update(target_begin, target_end, value, mid, end, idx * 2 + 1);
	}

	int get(const int target, const int begin, const int end, const int idx) {
		this->lazy_propagation(begin, end, idx);

		if (target < begin || end <= target) {
			return 0;
		}

		if (end - begin == 1) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target, begin, mid, idx * 2) + this->get(target, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->arr = vector<int>(N * 4, 0);
		this->lazy = vector<int>(N * 4, 0);
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target_begin, const int target_end, const int value) {
		this->update(target_begin, target_end, value, 0, this->N, 1);
	}

	int get(const int target) {
		return this->get(target, 0, this->N, 1);
	}
};

int dfs(const vector<vector<int>>& childs, vector<int>& new_id, vector<int>& graph_size, const int cur) {
	static int id_giver = 1;

	new_id[cur] = id_giver;
	++id_giver;

	int sz = 1;
	for (const int child_id : childs[cur]) {
		sz += dfs(childs, new_id, graph_size, child_id);
	}

	graph_size[new_id[cur]] = sz;
	return sz;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> salaries(N + 1);
	vector<int> parents(N + 1, -1);
	vector<vector<int>> childs(N + 1);

	cin >> salaries[1];

	for (int i = 2; i <= N; ++i) {
		cin >> salaries[i] >> parents[i];
		childs[parents[i]].push_back(i);
	}

	vector<int> new_id(N + 1);
	vector<int> graph_size(N + 1, 0);
	dfs(childs, new_id, graph_size, 1);

	vector<int> new_salaries(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		new_salaries[new_id[i]] = salaries[i];
	}

	Segtree segtree(new_salaries);

	for (int i = 0; i < M; ++i) {
		char op;
		cin >> op;

		if (op == 'p') {
			int a, x;
			cin >> a >> x;

			segtree.update(new_id[a], new_id[a] + graph_size[new_id[a]], x);
			segtree.update(new_id[a], new_id[a] + 1, -x);
		}
		else {
			int a;
			cin >> a;

			const int result = segtree.get(new_id[a]);
			printf("%d\n", result);
		}
	}

	return 0;
}