#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _change_query {
	int i;
	int v;
} ChangeQuery;

typedef struct _print_query {
	int k;
	int i;
	int j;
	int order;

	bool operator< (const struct _print_query &other) const {
		return this->k < other.k;
	}
} PrintQuery;

class Segment_tree {
private:
	int N;
	vector<long long> tree;

	long long init(const vector<int>& origin, const int begin, const int end, const int idx = 1) {
		long long& c = this->tree[idx];
		if (end - begin == 1) {
			return c = origin[begin];
		}

		const int mid = (begin + end) / 2;
		return c = this->init(origin, begin, mid, idx * 2) + this->init(origin, mid, end, idx * 2 + 1);
	}

	long long change(const int target_idx, const int target, const int begin, const int end, const int idx = 1) {
		long long& c = tree[idx];
		if (end <= target_idx || target_idx < begin) {
			return c;
		}

		if (end - begin == 1) {
			return c = target;
		}

		const int mid = (begin + end) / 2;
		return c = this->change(target_idx, target, begin, mid, idx * 2) + 
					this->change(target_idx, target, mid, end, idx * 2 + 1);
	}

	long long get_sum(const int target_begin, const int target_end, const int begin, const int end, const int idx = 1) const {
		if (end <= target_begin || target_end <= begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->tree[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get_sum(target_begin, target_end, begin, mid, idx * 2) + 
				this->get_sum(target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	Segment_tree(const vector<int>& origin) 
	: N((int)origin.size()), tree(vector<long long>(origin.size() * 4)) {
		this->init(origin, 0, this->N, 1);
	}

	void change(const int i, const int v) {
		this->change(i, v, 0, this->N, 1);
	}

	void change(const ChangeQuery& change_query) {
		this->change(change_query.i, change_query.v);
	}

	long long get_sum(const int i, const int j) const {
		return this->get_sum(i, j, 0, this->N, 1);
	}

	long long get_sum(const PrintQuery& print_query) const {
		return this->get_sum(print_query.i, print_query.j);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& n : arr) {
		scanf("%d", &n);
	}

	Segment_tree segtree(arr);

	int M;
	scanf("%d", &M);

	vector<ChangeQuery> change_queries;
	vector<PrintQuery> print_queries;
	int print_order = 0;
	for (int i = 0; i < M; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int i, v;
			scanf("%d%d", &i, &v);
			change_queries.push_back({ i - 1, v });
		}
		else {
			int k, i, j;
			scanf("%d%d%d", &k, &i, &j);
			print_queries.push_back({ k, i - 1, j, print_order });
			++print_order;
		}
	}

	sort(print_queries.begin(), print_queries.end());

	int change_idx = 0;
	vector<long long> results(print_order);
	for (const PrintQuery& print_query : print_queries) {
		while (change_idx < print_query.k) {
			segtree.change(change_queries[change_idx]);
			++change_idx;
		}

		const long long result = segtree.get_sum(print_query);
		results[print_query.order] = result;
	}

	for (const long long result : results) {
		printf("%lld\n", result);
	}

	return 0;
}