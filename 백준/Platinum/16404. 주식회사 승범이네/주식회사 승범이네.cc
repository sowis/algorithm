#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;
	vector<int> lazy;

	void lazy_progress(const int begin, const int end, const int idx) {
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
		this->lazy_progress(begin, end, idx);

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
		this->lazy_progress(begin, end, idx);

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
	Segtree(const int N)
		:N(N) {
		this->arr = vector<int>(this->N * 4, 0);
		this->lazy = vector<int>(this->N * 4, 0);
	}

	void update(const int target_begin, const int target_end, const int value) {
		this->update(target_begin, target_end, value, 0, this->N, 1);
	}

	int get(const int target) {
		return this->get(target, 0, this->N, 1);
	}
};

int dfs(const vector<vector<int>>& childs, vector<int>& new_id, vector<int>& graph_size, const int cur) {
	static int id_giver = 0;

	new_id[cur] = id_giver;
	++id_giver;

	int sz = 1;
	for (const int next : childs[cur]) {
		sz += dfs(childs, new_id, graph_size, next);
	}

	graph_size[cur] = sz;
	return sz;
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int parent;
	scanf("%d", &parent);


	vector<vector<int>> childs(N + 1);
	for (int i = 2; i <= N; ++i) {
		scanf("%d", &parent);

		childs[parent].push_back(i);
	}

	vector<int> new_id(N + 1);
	vector<int> graph_size(N + 1);
	dfs(childs, new_id, graph_size, 1);

	Segtree segtree(N + 1);

	for (int a = 0; a < M; ++a) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int i, w;
			scanf("%d%d", &i, &w);

			segtree.update(new_id[i], new_id[i] + graph_size[i], w);
		}
		else {
			int i;
			scanf("%d", &i);

			const int result = segtree.get(new_id[i]);
			printf("%d\n", result);
		}
	}

	return 0;
}