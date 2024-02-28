#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int sqrt_N;

typedef struct _query {
	int begin;
	int end;
	int order;

	bool operator< (const struct _query& other) const {
		if (this->begin / sqrt_N != other.begin / sqrt_N) {
			return this->begin / sqrt_N < other.begin / sqrt_N;
		}

		return this->end < other.end;
	}
} Query;

vector<int> appear(100001, 0);
vector<int> appear_count(100001, 0);
int result = 0;

void add(const int target) {
	if (appear[target] != 0) {
		--appear_count[appear[target]];
	}

	++appear[target];
	++appear_count[appear[target]];
	result = max(result, appear[target]);
}

void del(const int target) {
	--appear_count[appear[target]];

	if (appear[target] == result && appear_count[appear[target]] == 0) {
		--result;
	}

	--appear[target];
	++appear_count[appear[target]];
}

int main(void) {
	scanf("%d", &N);
	sqrt_N = (int)sqrt(N);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	int M;
	scanf("%d", &M);

	vector<Query> queries;
	for (int order = 0; order < M; ++order) {
		int begin, end;
		scanf("%d%d", &begin, &end);
		queries.push_back({ begin - 1, end, order });
	}

	sort(queries.begin(), queries.end());

	int begin = 0;
	int end = 0;
	vector<int> results(M);

	for (const Query& q : queries) {
		while (end < q.end) {
			add(arr[end]);
			++end;
		}

		while (q.end < end) {
			del(arr[end - 1]);
			--end;
		}

		while (begin < q.begin) {
			del(arr[begin]);
			++begin;
		}

		while (q.begin < begin) {
			add(arr[begin - 1]);
			--begin;
		}

		results[q.order] = result;
	}

	for (const int r : results) {
		printf("%d\n", r);
	}

	return 0;
}