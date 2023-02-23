#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N;
vector<int> seed;
vector<int> segtree;

int segtree_init(const int begin = 0, const int end = N, const int index = 1) {
	if (end - begin == 1) {
		return segtree[index] = seed[begin];
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = min(segtree_init(begin, mid, index * 2), segtree_init(mid, end, index * 2 + 1));
}

int segtree_get(const int target_begin, const int target_end, const int begin = 0, const int end = N, const int index = 1) {
	if (target_end <= begin || end <= target_begin) {
		return numeric_limits<int>::max();
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[index];
	}

	const int mid = (begin + end) / 2;
	return min(segtree_get(target_begin, target_end, begin, mid, index * 2), segtree_get(target_begin, target_end, mid, end, index * 2 + 1));
}

int segtree_update(const int target, const int value, const int begin = 0, const int end = N, const int index = 1) {
	if (target < begin || end <= target) {
		return segtree[index];
	}

	if (end - begin == 1) {
		return segtree[index] = value;
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = min(segtree_update(target, value, begin, mid, index * 2), segtree_update(target, value, mid, end, index * 2 + 1));
}

int main(void) {
	scanf("%d", &N);

	seed = vector<int>(N);
	segtree = vector<int>(N * 5);

	for (int& number : seed) {
		scanf("%d", &number);
	}

	segtree_init();

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);

		if (op == 1) {
			segtree_update(a - 1, b);
		}
		else {
			const int result = segtree_get(a - 1, b);
			printf("%d\n", result);
		}
	}

	return 0;
}