#include <iostream>
#include <vector>

using namespace std;

long long segtree_init(const vector<long long> &numbers, vector<long long>& segtree, const int begin, const int end, const int idx = 1) {
	if (end - begin <= 1) {
		return segtree[idx] = numbers[begin];
	}

	const int mid = (begin + end) / 2;
	const long long left = segtree_init(numbers, segtree, begin, mid, idx * 2);
	const long long right = segtree_init(numbers, segtree, mid, end, idx * 2 + 1);
	return segtree[idx] = left + right;
}

long long segtree_get(const vector<long long>& segtree, const int target_begin, const int target_end, const int begin, const int end, const int idx = 1) {
	if (target_end <= begin || end <= target_begin) {
		return 0;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[idx];
	}

	const int mid = (begin + end) / 2;
	const long long left = segtree_get(segtree, target_begin, target_end, begin, mid, idx * 2);
	const long long right = segtree_get(segtree, target_begin, target_end, mid, end, idx * 2 + 1);
	return left + right;
}

void test_case(void) {
	int N, Q;
	cin >> N >> Q;

	vector<long long> segtree(N * 5);
	vector<long long> numbers(N);
	for (long long& number : numbers) {
		cin >> number;
	}

	segtree_init(numbers, segtree, 0, N);

	for (int a = 0; a < Q; ++a) {
		int i, j;
		cin >> i >> j;
		const long long result = segtree_get(segtree, i, j + 1, 0, N);
		cout << result << "\n";
	}

	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}