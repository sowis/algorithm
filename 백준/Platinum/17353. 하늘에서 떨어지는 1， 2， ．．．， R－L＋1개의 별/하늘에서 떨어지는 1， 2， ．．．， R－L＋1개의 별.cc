#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	typedef struct _node {
		long long value; // [begin, end) 의 합
		long long lazy;
	} Node;

	long long N;
	vector<Node> tree;

	long long init(const vector<long long>& origin, const long long begin, const long long end, const long long idx = 1) {
		if (end - begin == 1) {
			return this->tree[idx].value = origin[begin];
		}

		const long long mid = (begin + end) / 2;
		const long long left = this->init(origin, begin, mid, idx * 2);
		const long long right = this->init(origin, mid, end, idx * 2 + 1);
		return this->tree[idx].value = left + right;
	}

	void lazy_handle(const long long begin, const long long end, const long long idx) {
		if (this->tree[idx].lazy == 0) {
			return;
		}

		this->tree[idx].value += (this->tree[idx].lazy * (end - begin));
		if (end - begin == 1) {
			this->tree[idx].lazy = 0;
			return;
		}

		this->tree[idx * 2].lazy += this->tree[idx].lazy;
		this->tree[idx * 2 + 1].lazy += this->tree[idx].lazy;
		this->tree[idx].lazy = 0;
	}

	long long update(const long long target_begin, const long long target_end, const long long change, const long long begin, const long long end, const long long idx = 1) {
		this->lazy_handle(begin, end, idx);

		if (end <= target_begin || target_end <= begin) {
			return this->tree[idx].value;
		}

		if (target_begin <= begin && end <= target_end) {
			this->tree[idx].value += change * (end - begin);

			if (end - begin != 1) {
				this->tree[idx * 2].lazy += change;
				this->tree[idx * 2 + 1].lazy += change;
			}

			return this->tree[idx].value;
		}

		const long long mid = (begin + end) / 2;
		const long long left = this->update(target_begin, target_end, change, begin, mid, idx * 2);
		const long long right = this->update(target_begin, target_end, change, mid, end, idx * 2 + 1);
		return this->tree[idx].value = left + right;
	}

	long long get_sum(const long long target_begin, const long long target_end, const long long begin, const long long end, const long long idx = 1) {
		this->lazy_handle(begin, end, idx);

		if (end <= target_begin || target_end <= begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->tree[idx].value;
		}

		const long long mid = (begin + end) / 2;
		const long long left = this->get_sum(target_begin, target_end, begin, mid, idx * 2);
		const long long right = this->get_sum(target_begin, target_end, mid, end, idx * 2 + 1);
		return left + right;
	}

public:
	Segtree(const vector<long long>& origin)
		:N((long long)origin.size()), tree(vector<Node>(N * 4, {0, 0})) {
		this->init(origin, 0, N, 1);
	}

	void update(const long long target_begin, const long long target_end, const long long change) {
		this->update(target_begin, target_end, change, 0, N, 1);
	}

	long long get_sum(const long long target) {
		return this->get_sum(0, target + 1, 0, N, 1);
	}
};

int main(void) {
	long long N;
	scanf("%lld", &N);

	vector<long long> A(N);
	for (long long& a : A) {
		scanf("%lld", &a);
	}

	vector<long long> A_change;
	A_change.push_back(A[0]);
	for (long long i = 1; i < N; ++i) {
		A_change.push_back(A[i] - A[i - 1]);
	}

	Segtree segtree(A_change);

	long long Q;
	scanf("%lld", &Q);

	for (long long i = 0; i < Q; ++i) {
		long long op;
		scanf("%lld", &op);

		if (op == 1) {
			long long L, R;
			scanf("%lld%lld", &L, &R);

			segtree.update(L - 1, R, 1);
			segtree.update(R, R + 1, -(R - L + 1));
		}
		else {
			long long X;
			scanf("%lld", &X);

			const long long result = segtree.get_sum(X - 1);
			printf("%lld\n", result);
		}
	}

	return 0;
}