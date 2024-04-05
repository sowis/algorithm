#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	constexpr static int N = 65536;
	vector<int> counts;

	void change(const int target, const int value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		this->counts[idx] += value;

		if (end - begin == 1) {
			return;
		}

		const int mid = (begin + end) / 2;
		this->change(target, value, begin, mid, idx * 2);
		this->change(target, value, mid, end, idx * 2 + 1);
	}

	int get_mid(const int left, const int begin, const int end, const int idx) const {
		if (left < 0) {
			return -1;
		}

		if (this->counts[idx] <= left) {
			return -1;
		}

		if (end - begin == 1) {
			return begin;
		}

		const int mid = (begin + end) / 2;
		return max(get_mid(left, begin, mid, idx * 2), get_mid(left - this->counts[idx * 2], mid, end, idx * 2 + 1));
	}

public:
	Segtree(void)
		:counts(vector<int>(N * 4, 0)) {}

	void insert(const int target) {
		this->change(target, 1, 0, this->N, 1);
	}

	void remove(const int target) {
		this->change(target, -1, 0, this->N, 1);
	}

	int get_mid(const int K) const {
		const int left = (K % 2) ? K / 2 : K / 2 - 1;
		return this->get_mid(left, 0, this->N, 1);
	}
};

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> inputs(N);
	for (int& input : inputs) {
		scanf("%d", &input);
	}

	Segtree segtree;
	long long result = 0;

	for (int i = 0; i < K - 1; ++i) {
		segtree.insert(inputs[i]);
	}

	for (int i = K - 1; i < N; ++i) {
		segtree.insert(inputs[i]);
		result += segtree.get_mid(K);
		segtree.remove(inputs[i - (K - 1)]);
	}

	printf("%lld\n", result);

	return 0;
}