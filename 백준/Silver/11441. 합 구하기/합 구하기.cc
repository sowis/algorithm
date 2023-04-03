#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> seeds;
vector<int> segtree;

int segtree_init(const int begin = 0, const int end = N, const int index = 1) {
	if (end - begin == 1) {
		return segtree[index] = seeds[begin];
	}

	const int mid = (begin + end) / 2;
	return segtree[index] = segtree_init(begin, mid, index * 2) + segtree_init(mid, end, index * 2 + 1);
}

int segtree_get(const int target_begin, const int target_end, const int begin = 0, const int end = N, const int index = 1) {
	if (target_end <= begin || end <= target_begin) {
		return 0;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[index];
	}

	const int mid = (begin + end) / 2;
	return segtree_get(target_begin, target_end, begin, mid, index * 2) + segtree_get(target_begin, target_end, mid, end, index * 2 + 1);
}

int main(void) {
	scanf("%d", &N);

	seeds = vector<int>(N);
	segtree = vector<int>(N * 5);

	for (int& seed : seeds) {
		scanf("%d", &seed);
	}

	segtree_init();

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int begin, end;
		scanf("%d%d", &begin, &end);

		const int result = segtree_get(begin - 1, end);
		printf("%d\n", result);
	}

	return 0;
}