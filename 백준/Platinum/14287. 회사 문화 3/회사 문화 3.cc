#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;

	void update(const int target, const int add, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			arr[idx] += add;
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target, add, begin, mid, idx * 2);
		this->update(target, add, mid, end, idx * 2 + 1);
		this->arr[idx] = this->arr[idx * 2] + this->arr[idx * 2 + 1];
	}

	int get(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target_begin, target_end, begin, mid, idx * 2) + this->get(target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const int N)
		:N(N) {
		this->arr = vector<int>(this->N * 4, 0);
	}

	void update(const int target, const int add) {
		this->update(target, add, 0, this->N, 1);
	}

	int get(const int target_begin, const int target_end) const {
		return this->get(target_begin, target_end, 0, this->N, 1);
	}
};

int dfs(const vector<vector<int>>& childs, vector<int>& new_id, vector<int>& graph_size, const int cur) {
	static int id_giver = 0;
	new_id[cur] = id_giver;
	++id_giver;

	int sz = 1;
	for (const int child : childs[cur]) {
		sz += dfs(childs, new_id, graph_size, child);
	}

	graph_size[cur] = sz;
	return sz;
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> childs(N + 1);
	for (int child = 1; child <= N; ++child) {
		int parent;
		scanf("%d", &parent);

		if (parent == -1) {
			continue;
		}

		childs[parent].push_back(child);
	}

	vector<int> new_id(N + 1, 0);
	vector<int> graph_size(N + 1, 0);
	dfs(childs, new_id, graph_size, 1);

	Segtree segtree(N + 1);

	for (int a = 0; a < M; ++a) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int i, w;
			scanf("%d%d", &i, &w);

			segtree.update(new_id[i], w);
		}
		else {
			int i;
			scanf("%d", &i);

			const int result = segtree.get(new_id[i], new_id[i] + graph_size[i]);
			printf("%d\n", result);
		}
	}

	return 0;
}