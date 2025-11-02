#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> heights;
vector<int> segtree;
vector<int> lazy;

void lazy_handle(const int begin, const int end, const int idx) {
	segtree[idx] += lazy[idx];
	if (end - begin == 1) {
		lazy[idx] = 0;
		return;
	}

	lazy[idx * 2] += lazy[idx];
	lazy[idx * 2 + 1] += lazy[idx];
	lazy[idx] = 0;
}

int segtree_init(const int begin, const int end, const int idx = 1) {
	if (end - begin == 1) {
		return segtree[idx] = heights[begin];
	}

	const int mid = (begin + end) / 2;
	return segtree[idx] = segtree_init(begin, mid, idx * 2) + segtree_init(mid, end, idx * 2 + 1);
}

int segtree_add(const int begin, const int end, const int idx, const int target_begin, const int target_end, const int value) {
	lazy_handle(begin, end, idx);
	if (target_end <= begin || end <= target_begin) {
		return segtree[idx];
	}

	if (target_begin <= begin && end <= target_end) {
		lazy[idx] += value;
		lazy_handle(begin, end, idx);
		return segtree[idx];
	}

	const int mid = (begin + end) / 2;
	const int left = segtree_add(begin, mid, idx * 2, target_begin, target_end, value);
	const int right = segtree_add(mid, end, idx * 2 + 1, target_begin, target_end, value);
	return segtree[idx] = left + right;
}

int segtree_get(const int begin, const int end, const int idx, const int target_idx) {
	lazy_handle(begin, end, idx);

	if (end <= target_idx || target_idx < begin) {
		return 0;
	}

	if (end - begin == 1) {
		return segtree[idx];
	}

	const int mid = (begin + end) / 2;
	const int left = segtree_get(begin, mid, idx * 2, target_idx);
	const int right = segtree_get(mid, end, idx * 2 + 1, target_idx);
	return left + right;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	heights = vector<int>(N);
	for (int& height : heights) {
		cin >> height;
	}
	
	segtree = vector<int>(N * 4);
	lazy = vector<int>(N * 4, 0);
	segtree_init(0, N);

	for (int i = 0; i < M; ++i) {
		int a, b, k;
		cin >> a >> b >> k;

		--a; // 0부터 시작하도록..

		segtree_add(0, N, 1, a, b, k);
	}

	for (int i = 0; i < N; ++i) {
		cout << segtree_get(0, N, 1, i) << " ";
	}

	return 0;
}