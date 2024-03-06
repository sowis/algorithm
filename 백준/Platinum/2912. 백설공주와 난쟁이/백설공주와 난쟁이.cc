#include <cstdio>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N, C;
int sqrt_N;

typedef struct _query {
	int A;
	int B;
	int idx;

	bool operator<(const struct _query& q) const {
		if (this->A / sqrt_N != q.A / sqrt_N) {
			return this->A / sqrt_N < q.A / sqrt_N;
		}

		return this->B < q.B;
	}
} Query;

int pretty_color(const vector<int>& color_counts, const int K) {
	for (int color = 1; color <= C; ++color) {
		if (K / 2 < color_counts[color]) {
			return color;
		}
	}

	return -1;
}

int main(void) {
	scanf("%d%d", &N, &C);

	sqrt_N = (int)sqrt(N);

	vector<int> arr(N);
	for (int& color : arr) {
		scanf("%d", &color);
	}

	int M;
	scanf("%d", &M);

	vector<Query> queries(M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &queries[i].A, &queries[i].B);
		--queries[i].A;
		queries[i].idx = i;
	}

	sort(queries.begin(), queries.end());

	int begin = 0;
	int end = 0;
	vector<int> color_counts(C + 1, 0);
	vector<int> results(M);
	
	for (const Query& q : queries) {
		while (q.A < begin) {
			++color_counts[arr[begin - 1]];
			--begin;
		}

		while (end < q.B) {
			++color_counts[arr[end]];
			++end;
		}

		while (begin < q.A) {
			--color_counts[arr[begin]];
			++begin;
		}

		while (q.B < end) {
			--color_counts[arr[end - 1]];
			--end;
		}

		const int len = end - begin;
		results[q.idx] = pretty_color(color_counts, len);
	}

	for (const int result : results) {
		if (result == -1) {
			printf("no\n");
		}
		else {
			printf("yes %d\n", result);
		}
	}

	return 0;
}