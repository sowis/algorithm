#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long left_seq_zero;
	long long right_seq_zero;
	long long max_seq_zero;
	bool all_zero;
	long long value; // 단말 노드에서만 유효
} Data;

long long N, M;
vector<long long> A, A_diff, A_diff_diff;
vector<Data> segtree;

void segtree_merge(const long long begin, const long long end, const long long idx) {
	if (end - begin <= 1) {
		return;
	}

	if (segtree[idx * 2].all_zero) {
		segtree[idx].left_seq_zero = segtree[idx * 2].max_seq_zero + segtree[idx * 2 + 1].left_seq_zero;
	}
	else {
		segtree[idx].left_seq_zero = segtree[idx * 2].left_seq_zero;
	}

	if (segtree[idx * 2 + 1].all_zero) {
		segtree[idx].right_seq_zero = segtree[idx * 2].right_seq_zero + segtree[idx * 2 + 1].max_seq_zero;
	}
	else {
		segtree[idx].right_seq_zero = segtree[idx * 2 + 1].right_seq_zero;
	}

	const long long mid_seq_zero = segtree[idx * 2].right_seq_zero + segtree[idx * 2 + 1].left_seq_zero;
	segtree[idx].max_seq_zero = max(segtree[idx * 2].max_seq_zero, segtree[idx * 2 + 1].max_seq_zero);
	segtree[idx].max_seq_zero = max(segtree[idx].max_seq_zero, max(max(segtree[idx].left_seq_zero, segtree[idx].right_seq_zero), mid_seq_zero));
	segtree[idx].all_zero = (segtree[idx * 2].all_zero && segtree[idx * 2 + 1].all_zero);
}

void segtree_init(const long long begin, const long long end, const long long idx) {
	if (end - begin < 1) {
		return;
	}

	if (end - begin == 1) {
		segtree[idx].value = A_diff_diff[begin];
		segtree[idx].left_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].right_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].max_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].all_zero = (segtree[idx].value == 0);
		return;
	}

	const long long mid = (begin + end) / 2;
	segtree_init(begin, mid, idx * 2);
	segtree_init(mid, end, idx * 2 + 1);
	segtree_merge(begin, end, idx);
}

void segtree_add(const long long target, const long long value, const long long begin, const long long end, const long long idx) {
	if (target < begin || end <= target) {
		return;
	}

	if (end - begin == 1) {
		segtree[idx].value += value;
		segtree[idx].left_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].right_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].max_seq_zero = ((segtree[idx].value == 0) ? 1 : 0);
		segtree[idx].all_zero = (segtree[idx].value == 0);
		return;
	}

	const long long mid = (begin + end) / 2;
	segtree_add(target, value, begin, mid, idx * 2);
	segtree_add(target, value, mid, end, idx * 2 + 1);
	segtree_merge(begin, end, idx);
}

Data segtree_get(const long long target_begin, const long long target_end, const long long begin, const long long end, const long long idx) {
	if (target_end <= begin || end <= target_begin) {
		return Data{ 0, 0, 0, true, 0 };
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[idx];
	}

	const long long mid = (begin + end) / 2;
	const Data left = segtree_get(target_begin, target_end, begin, mid, idx * 2);
	const Data right = segtree_get(target_begin, target_end, mid, end, idx * 2 + 1);
	Data result{ 0, 0, 0, false, 0 };

	if (left.all_zero) {
		result.left_seq_zero = left.max_seq_zero + right.left_seq_zero;
	}
	else {
		result.left_seq_zero = left.left_seq_zero;
	}

	if (right.all_zero) {
		result.right_seq_zero = left.right_seq_zero + right.max_seq_zero;
	}
	else {
		result.right_seq_zero = right.right_seq_zero;
	}

	const long long mid_seq_zero = left.right_seq_zero + right.left_seq_zero;
	result.max_seq_zero = max(left.max_seq_zero, right.max_seq_zero);
	result.max_seq_zero = max(result.max_seq_zero, max(max(result.left_seq_zero, result.right_seq_zero), mid_seq_zero));
	result.all_zero = (left.all_zero && right.all_zero);
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	A = vector<long long>(N);
	
	for (long long& a : A) {
		cin >> a;
	}

	for (int i = 1; i < A.size(); ++i) {
		A_diff.push_back(A[i] - A[i - 1]);
	}

	for (int i = 1; i < A_diff.size(); ++i) {
		A_diff_diff.push_back(A_diff[i] - A_diff[i - 1]);
	}

	segtree = vector<Data>(A_diff_diff.size() * 4);
	segtree_init(0, (long long)A_diff_diff.size(), 1);

	cin >> M;
	while (M--) {
		long long op;
		cin >> op;

		if (op == 1) {
			long long i, j, x, y;
			cin >> i >> j >> x >> y;
			
			if (0 <= i - 3 && i - 3 < (long long)A_diff_diff.size()) {
				segtree_add(i - 3, x, 0, (long long)A_diff_diff.size(), 1);
			}

			if (0 <= i - 2 && i - 2 < (long long)A_diff_diff.size()) {
				segtree_add(i - 2, y - x, 0, (long long)A_diff_diff.size(), 1);
			}

			if (0 <= j - 2 && j - 2 < (long long)A_diff_diff.size()) {
				segtree_add(j - 2, -x - (j - i + 1) * y, 0, (long long)A_diff_diff.size(), 1);
			}

			if (0 <= j - 1 && j - 1 < (long long)A_diff_diff.size()) {
				segtree_add(j - 1, x + (j - i) * y, 0, (long long)A_diff_diff.size(), 1);
			}
		}
		else if (op == 2) {
			long long i, j;
			cin >> i >> j;

			if (i + 1 == j) {
				cout << 2 << "\n";
				continue;
			}

			const long long target_begin = max(0LL, i - 1);
			const long long target_end = min(j - 2, (long long)A_diff_diff.size());
			cout << segtree_get(target_begin, target_end, 0, (long long)A_diff_diff.size(), 1).max_seq_zero + 2 << "\n";
		}
	}

	return 0;
}