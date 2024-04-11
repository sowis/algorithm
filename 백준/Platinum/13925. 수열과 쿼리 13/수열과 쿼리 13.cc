#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	constexpr static long long MOD = 1000000000 + 7;
	int N;
	vector<long long> value;
	vector<long long> lazy_mul;
	vector<long long> lazy_add;

	void init(const vector<long long>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->value[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
		this->value[idx] = (this->value[idx * 2] + this->value[idx * 2 + 1]) % this->MOD;
	}

	void lazy_progress(const int begin, const int end, const int idx) {
		this->value[idx] *= this->lazy_mul[idx];
		this->value[idx] %= this->MOD;
		this->value[idx] += this->lazy_add[idx] * (end - begin);
		this->value[idx] %= this->MOD;

		if (end - begin == 1) {
			this->lazy_mul[idx] = 1;
			this->lazy_add[idx] = 0;
			return;
		}

		this->lazy_mul[idx * 2] *= this->lazy_mul[idx];
		this->lazy_add[idx * 2] *= this->lazy_mul[idx];
		this->lazy_add[idx * 2] += this->lazy_add[idx];
		this->lazy_mul[idx * 2] %= this->MOD;
		this->lazy_add[idx * 2] %= this->MOD;

		this->lazy_mul[idx * 2 + 1] *= this->lazy_mul[idx];
		this->lazy_add[idx * 2 + 1] *= this->lazy_mul[idx];
		this->lazy_add[idx * 2 + 1] += this->lazy_add[idx];
		this->lazy_mul[idx * 2 + 1] %= this->MOD;
		this->lazy_add[idx * 2 + 1] %= this->MOD;

		this->lazy_mul[idx] = 1;
		this->lazy_add[idx] = 0;
	}

	void update(const int target_begin, const int target_end, const long long mul, const long long add, const int begin, const int end, const int idx) {
		this->lazy_progress(begin, end, idx);

		if (target_end <= begin || end <= target_begin) {
			return;
		}

		if (target_begin <= begin && end <= target_end) {
			this->lazy_mul[idx] = mul;
			this->lazy_add[idx] = add;

			this->lazy_progress(begin, end, idx);
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target_begin, target_end, mul, add, begin, mid, idx * 2);
		this->update(target_begin, target_end, mul, add, mid, end, idx * 2 + 1);
		this->value[idx] = (this->value[idx * 2] + this->value[idx * 2 + 1]) % this->MOD;
	}

	long long get(const int target_begin, const int target_end, const int begin, const int end, const int idx) {
		this->lazy_progress(begin, end, idx);

		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->value[idx];
		}

		const int mid = (begin + end) / 2;
		return (this->get(target_begin, target_end, begin, mid, idx * 2) + this->get(target_begin, target_end, mid, end, idx * 2 + 1)) % this->MOD;
	}

public:
	Segtree(const vector<long long>& origin)
		:N((int)origin.size()) {
		this->value = vector<long long>(this->N * 4, 0);
		this->lazy_mul = vector<long long>(this->N * 4, 1);
		this->lazy_add = vector<long long>(this->N * 4, 0);

		this->init(origin, 0, this->N, 1);
	}

	void update(const int target_begin, const int target_end, const long long mul = 1, const long long add = 0) {
		this->update(target_begin, target_end, mul, add, 0, this->N, 1);
	}

	long long get(const int target_begin, const int target_end) {
		return this->get(target_begin, target_end, 0, this->N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<long long> origin(N);
	for (long long& num : origin) {
		scanf("%lld", &num);
	}

	Segtree segtree(origin);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);

			segtree.update(x - 1, y, 1, v);
		}
		else if (op == 2) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);

			segtree.update(x - 1, y, v, 0);
		}
		else if (op == 3) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);

			segtree.update(x - 1, y, 0, v);
		}
		else {
			int x, y;
			scanf("%d%d", &x, &y);

			const long long result = segtree.get(x - 1, y);
			printf("%lld\n", result);
		}
	}

	return 0;
}