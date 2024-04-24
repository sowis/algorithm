#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long small, long long big) {
	if (small > big) {
		swap(small, big);
	}

	while (small > 0) {
		const long long remain = big % small;
		big = small;
		small = remain;
	}

	return big;
}

class Segtree {
private:
	int N;
	vector<long long> arr;
	vector<long long> lazy;

	void init(const vector<long long>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
	}

	void lazy_propagation(const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] += this->lazy[idx];
			this->lazy[idx] = 0;
			return;
		}

		const int mid = (begin + end) / 2;
		this->lazy[idx * 2] += this->lazy[idx];
		this->lazy[idx * 2 + 1] += this->lazy[idx];
		this->lazy[idx] = 0;
	}

	void update(const int target_begin, const int target_end, const long long value, const int begin, const int end, const int idx) {
		this->lazy_propagation(begin, end, idx);

		if (end <= target_begin || target_end <= begin) {
			return;
		}

		if (target_begin <= begin && end <= target_end) {
			this->lazy[idx] += value;
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target_begin, target_end, value, begin, mid, idx * 2);
		this->update(target_begin, target_end, value, mid, end, idx * 2 + 1);
	}

	long long get(const int target, const int begin, const int end, const int idx) {
		this->lazy_propagation(begin, end, idx);

		if (target < begin || end <= target) {
			return 0;
		}

		if (end - begin == 1) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target, begin, mid, idx * 2) + this->get(target, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const vector<long long>& origin)
		:N((int)origin.size()) {
		this->arr = vector<long long>(N * 4, 0);
		this->lazy = vector<long long>(N * 4, 0);
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target_begin, const int target_end, const long long value) {
		this->update(target_begin, target_end, value, 0, this->N, 1);
	}

	long long get(const int target) {
		return get(target, 0, this->N, 1);
	}
};

class GCD_segtree {
private:
	int N;
	vector<long long> arr;

	void init(const vector<long long>& diff, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = diff[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(diff, begin, mid, idx * 2);
		this->init(diff, mid, end, idx * 2 + 1);
		this->arr[idx] = gcd(this->arr[idx * 2], this->arr[idx * 2 + 1]);
	}

	void update(const int target, const long long value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			this->arr[idx] = value;
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target, value, begin, mid, idx * 2);
		this->update(target, value, mid, end, idx * 2 + 1);
		this->arr[idx] = gcd(this->arr[idx * 2], this->arr[idx * 2 + 1]);
	}

	long long get_gcd(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return -1;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		const long long left = get_gcd(target_begin, target_end, begin, mid, idx * 2);
		const long long right = get_gcd(target_begin, target_end, mid, end, idx * 2 + 1);

		if (left == -1) {
			return right;
		}

		if (right == -1) {
			return left;
		}

		return gcd(left, right);
	}

public:
	GCD_segtree(const vector<long long>& diff)
		:N((int)diff.size()) {
		this->arr = vector<long long>(this->N * 4, 0);
		this->init(diff, 0, this->N, 1);
	}

	void update(const int target, const long long value) {
		this->update(target, value, 0, this->N, 1);
	}

	long long get_gcd(const int target_begin, const int target_end) const {
		return this->get_gcd(target_begin, target_end, 0, this->N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<long long> origin(N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld\n", &origin[i]);
	}

	vector<long long> diff(N + 1, 0);
	for (int i = 1; i < N + 2; ++i) {
		diff[i - 1] = abs(origin[i] - origin[i - 1]);
	}

	Segtree segtree(origin);
	GCD_segtree gcd_segtree(diff);

	int Q;
	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i) {
		long long T;
		int A, B;
		scanf("%lld%d%d", &T, &A, &B);

		if (T == 0) {
			if (A == B) {
				const long long result = segtree.get(A);
				printf("%lld\n", result);
			}
			else {
				const long long result = gcd(segtree.get(A), gcd_segtree.get_gcd(A, B));
				printf("%lld\n", result);
			}
		}
		else {
			segtree.update(A, B + 1, T);

			long long left = segtree.get(A - 1);
			long long right = segtree.get(A);
			long long diff = abs(left - right);
			gcd_segtree.update(A - 1, diff);

			left = segtree.get(B);
			right = segtree.get(B + 1);
			diff = abs(left - right);
			gcd_segtree.update(B, diff);
		}
	}

	return 0;
}