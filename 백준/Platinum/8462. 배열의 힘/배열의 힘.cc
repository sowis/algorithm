#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long sqrt_N;

typedef struct _query {
	long long l;
	long long r;
	long long idx;

	bool operator< (const struct _query& q) const {
		if (this->l / sqrt_N != q.l / sqrt_N) {
			return this->l / sqrt_N < q.l / sqrt_N;
		}

		return this->r < q.r;
	}
} Query;

vector<long long> arr;
long long K[1000001];
long long power = 0;

void insert(const long long number) {
	power -= K[number] * K[number] * number;
	++K[number];
	power += K[number] * K[number] * number;
}

void remove(const long long number) {
	power -= K[number] * K[number] * number;
	--K[number];
	power += K[number] * K[number] * number;
}

int main(void) {
	long long n, t;
	scanf("%lld%lld", &n, &t);

	sqrt_N = (long long)sqrt(n);

	arr = vector<long long>(n);
	for (long long& num : arr) {
		scanf("%lld", &num);
	}

	vector<Query> queries(t);
	for (long long i = 0; i < t; ++i) {
		scanf("%lld%lld", &queries[i].l, &queries[i].r);
		queries[i].idx = i;
		--queries[i].l;
	}

	sort(queries.begin(), queries.end());

	long long begin = 0;
	long long end = 0;
	vector<long long> results(t);
	for (const Query& q : queries) {
		while (end < q.r) {
			insert(arr[end]);
			++end;
		}

		while (q.l < begin) {
			insert(arr[begin - 1]);
			--begin;
		}

		while (q.r < end) {
			remove(arr[end - 1]);
			--end;
		}

		while (begin < q.l) {
			remove(arr[begin]);
			++begin;
		}

		results[q.idx] = power;
	}

	for (const long long result : results) {
		printf("%lld\n", result);
	}

	return 0;
}