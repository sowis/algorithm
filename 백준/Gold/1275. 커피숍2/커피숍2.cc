#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<long long> segtree(500000);
vector<long long> seeds;

long long segtree_init(const int begin = 0, const int end = N, const int index = 1) {
	if (end - begin == 1) {
		return segtree[index] = seeds[begin];
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = segtree_init(begin, mid, index * 2) + segtree_init(mid, end, index * 2 + 1);
}

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

long long segtree_update(const int target_index, const long long target, const int begin = 0, const int end = N, const int index = 1) {
	if (target_index < begin || end <= target_index) {
		return segtree[index];
	}

	if (end - begin == 1) {
		return segtree[index] = target;
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = segtree_update(target_index, target, begin, mid, index * 2) + segtree_update(target_index, target, mid, end, index * 2 + 1);
}

int main(void) {
	scanf("%d%d", &N, &Q);

	seeds = vector<long long>(N);
	for (long long& seed : seeds) {
		scanf("%lld", &seed);
	}

	segtree_init();

	for (int i = 0; i < Q; ++i) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);

		if (x > y) {
			swap(x, y);
		}

		const long long result = segtree_get(x - 1, y);
		segtree_update(a - 1, b);

		printf("%lld\n", result);
	}

	return 0;
}