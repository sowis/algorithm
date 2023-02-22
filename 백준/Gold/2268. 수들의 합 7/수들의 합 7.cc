#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> segtree;

long long segtree_get(const int target_begin, const int target_end, const int begin = 0, const int end = N, const int index = 1) {
	if (target_end <= begin || end <= target_begin) {
		return 0;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[index];
	}

	const int mid = (begin + end) / 2;
	return segtree_get(target_begin, target_end, begin, mid, index * 2) + segtree_get(target_begin, target_end, mid, end, index * 2 + 1);
}

long long segtree_update(const int target, const int value, const int begin = 0, const int end = N, const int index = 1) {
	if (target < begin || end <= target) {
		return segtree[index];
	}

	if (end - begin == 1) {
		return segtree[index] = value;
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = segtree_update(target, value, begin, mid, index * 2) + segtree_update(target, value, mid, end, index * 2 + 1);
}

int main(void) {
	scanf("%d%d", &N, &M);

	segtree = vector<long long>(N * 10, 0);

	for (int i = 0; i < M; ++i) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);

		if (op == 0) {
			if (a > b) {
				swap(a, b);
			}

			printf("%lld\n", segtree_get(a - 1, b));
		}
		else {
			segtree_update(a - 1, b);
		}
	}

	return 0;
}