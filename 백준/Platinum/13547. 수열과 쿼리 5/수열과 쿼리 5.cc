#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int sqrt_N;

typedef struct _query {
	int idx;
	int begin;
	int end;

	bool operator<(const struct _query& q) const {
		if (this->begin / sqrt_N != q.begin / sqrt_N) {
			return this->begin / sqrt_N < q.begin / sqrt_N;
		}

		return this->end < q.end;
	}
} Query;

int main(void) {
	scanf("%d", &N);
	sqrt_N = sqrt(N);

	vector<int> arr(N);
	for (int& n : arr) {
		scanf("%d", &n);
	}

	int M;
	scanf("%d", &M);

	vector<Query> queries(M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &queries[i].begin, &queries[i].end);
		--queries[i].begin;
		queries[i].idx = i;
	}

	sort(queries.begin(), queries.end());

	vector<int> number_count(1000001, 0);
	vector<int> results(M);
	int union_size = 0;
	for (int i = queries[0].begin; i < queries[0].end; ++i) {
		if (number_count[arr[i]] == 0) {
			++union_size;
		}

		++number_count[arr[i]];
	}

	results[queries[0].idx] = union_size;
	int begin = queries[0].begin;
	int end = queries[0].end;

	for (int i = 1; i < M; ++i) {
		const Query& q = queries[i];
		while (begin < q.begin) {
			if (number_count[arr[begin]] == 1) {
				--union_size;
			}

			--number_count[arr[begin]];
			++begin;
		}

		while (begin > q.begin) {
			--begin;
			if (number_count[arr[begin]] == 0) {
				++union_size;
			}

			++number_count[arr[begin]];
		}

		while (end < q.end) {
			if (number_count[arr[end]] == 0) {
				++union_size;
			}

			++number_count[arr[end]];
			++end;
		}

		while (end > q.end) {
			--end;
			if (number_count[arr[end]] == 1) {
				--union_size;
			}

			--number_count[arr[end]];
		}

		results[q.idx] = union_size;
	}

	for (const int result : results) {
		printf("%d\n", result);
	}

	return 0;
}