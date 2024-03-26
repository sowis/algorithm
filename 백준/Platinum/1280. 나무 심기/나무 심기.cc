#include <cstdio>
#include <vector>

using namespace std;

#define sum first
#define count second

constexpr long long DIV = 1000000007;
constexpr int MAX = 200000;

pair<long long, long long> tree[200001 * 4]; // { sum, count }

void insert(const long long target, const int begin, const int end, const int idx) {
	if (target < begin || end <= target) {
		return;
	}

	tree[idx].sum += target;
	++tree[idx].count;

	if (end - begin == 1) {
		return;
	}

	const int mid = (begin + end) / 2;
	insert(target, begin, mid, idx * 2);
	insert(target, mid, end, idx * 2 + 1);
}

pair<long long, long long> query(const int target_begin, const int target_end, const int begin, const int end, const int idx) {
	if (target_end <= begin || end <= target_begin) {
		return { 0, 0 };
	}

	if (target_begin <= begin && end <= target_end) {
		return tree[idx];
	}

	const int mid = (begin + end) / 2;
	const pair<long long, long long> left = query(target_begin, target_end, begin, mid, idx * 2);
	const pair<long long, long long> right = query(target_begin, target_end, mid, end, idx * 2 + 1);
	return { left.sum + right.sum, left.count + right.count };
}

int main(void) {
	int N;
	scanf("%d", &N);

	long long result = 1;
	long long pos;

	scanf("%lld", &pos);
	insert(pos, 0, MAX, 1);

	for (int i = 1; i < N; ++i) {
		scanf("%lld", &pos);

		const pair<long long, long long> left = query(0, (int)pos, 0, MAX, 1);
		const pair<long long, long long> right = query((int)pos + 1, MAX, 0, MAX, 1);
		const long long mul = (((pos * left.count) - left.sum) % DIV + (right.sum - (pos * right.count)) % DIV) % DIV;
		result *= mul;
		result %= DIV;
		insert(pos, 0, MAX, 1);
	}

	printf("%lld\n", result);

	return 0;
}