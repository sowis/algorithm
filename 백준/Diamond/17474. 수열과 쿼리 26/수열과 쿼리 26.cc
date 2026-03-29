#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long sum;
	long long max_value;
	long long second_max_value;
	long long max_count;
} Data;

int N;
vector<long long> v;
vector<Data> segtree;

void segtree_merge(const int id) {
	const int left = id * 2;
	const int right = id * 2 + 1;

	segtree[id].sum = segtree[left].sum + segtree[right].sum;
	if (segtree[left].max_value == segtree[right].max_value) {
		segtree[id].max_value = segtree[left].max_value;
		segtree[id].max_count = segtree[left].max_count + segtree[right].max_count;
		segtree[id].second_max_value = max(segtree[left].second_max_value, segtree[right].second_max_value);
	}
	else if (segtree[left].max_value > segtree[right].max_value) {
		segtree[id].max_value = segtree[left].max_value;
		segtree[id].max_count = segtree[left].max_count;
		segtree[id].second_max_value = max(segtree[left].second_max_value, segtree[right].max_value);
	}
	else {
		segtree[id].max_value = segtree[right].max_value;
		segtree[id].max_count = segtree[right].max_count;
		segtree[id].second_max_value = max(segtree[right].second_max_value, segtree[left].max_value);
	}
}

void segtree_init(const int begin, const int end, const int id = 1) {
	if (end - begin == 1) {
		segtree[id].sum = v[begin];
		segtree[id].max_value = v[begin];
		segtree[id].second_max_value = -1;
		segtree[id].max_count = 1;
		return;
	}

	const int mid = (begin + end) / 2;
	segtree_init(begin, mid, id * 2);
	segtree_init(mid, end, id * 2 + 1);
	segtree_merge(id);
}

void segtree_propagation(const int begin, const int end, const int id) {
	if (end - begin == 1) {
		return;
	}

	const int left = id * 2;
	const int right = id * 2 + 1;

	if (segtree[left].max_value > segtree[id].max_value) {
		segtree[left].sum -= (segtree[left].max_value - segtree[id].max_value) * segtree[left].max_count;
		segtree[left].max_value = segtree[id].max_value;
	}
	
	if (segtree[right].max_value > segtree[id].max_value) {
		segtree[right].sum -= (segtree[right].max_value - segtree[id].max_value) * segtree[right].max_count;
		segtree[right].max_value = segtree[id].max_value;
	}
}

void segtree_update(const int begin, const int end, const int target_begin, const int target_end, const long long value, const int id) {
	if (target_end <= begin || end <= target_begin || segtree[id].max_value <= value) {
		return;
	}

	if (target_begin <= begin && end <= target_end && segtree[id].second_max_value < value) {
		segtree[id].sum -= (segtree[id].max_value - value) * segtree[id].max_count;
		segtree[id].max_value = value;
		return;
	}

	segtree_propagation(begin, end, id);
	const int mid = (begin + end) / 2;
	segtree_update(begin, mid, target_begin, target_end, value, id * 2);
	segtree_update(mid, end, target_begin, target_end, value, id * 2 + 1);
	segtree_merge(id);
}

long long segtree_get_max_value(const int begin, const int end, const int target_begin, const int target_end, const int id) {
	if (target_end <= begin || end <= target_begin) {
		return 0LL;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[id].max_value;
	}

	segtree_propagation(begin, end, id);
	const int mid = (begin + end) / 2;
	return max(segtree_get_max_value(begin, mid, target_begin, target_end, id * 2), segtree_get_max_value(mid, end, target_begin, target_end, id * 2 + 1));
}

long long segtree_get_sum(const int begin, const int end, const int target_begin, const int target_end, const int id) {
	if (target_end <= begin || end <= target_begin) {
		return 0LL;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[id].sum;
	}

	segtree_propagation(begin, end, id);
	const int mid = (begin + end) / 2;
	return segtree_get_sum(begin, mid, target_begin, target_end, id * 2) + segtree_get_sum(mid, end, target_begin, target_end, id * 2 + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	v = vector<long long>(N);
	segtree = vector<Data>(N * 4);

	for (long long& number : v) {
		cin >> number;
	}

	segtree_init(0, N);

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int op;
		cin >> op;

		if (op == 1) {
			int L, R, X;
			cin >> L >> R >> X;

			segtree_update(0, N, L - 1, R, X, 1);
		}
		else if (op == 2) {
			int L, R;
			cin >> L >> R;

			cout << segtree_get_max_value(0, N, L - 1, R, 1) << "\n";
		}
		else {
			int L, R;
			cin >> L >> R;

			cout << segtree_get_sum(0, N, L - 1, R, 1) << "\n";
		}
	}

	return 0;
}