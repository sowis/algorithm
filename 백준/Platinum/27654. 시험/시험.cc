#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long a;
	long long b;
	double key;

	bool operator<(const _data& d) const {
		return this->key > d.key;
	}
} Data;

long long N, K;
vector<Data> scores;

bool parametric_search(const double target_sum) {
	for (Data& d : scores) {
		d.key = d.a - (d.b * target_sum);
	}

	sort(scores.begin(), scores.end());

	double key_sum = 0;
	for (int i = 0; i < K; ++i) {
		key_sum += scores[i].key;
	}

	return key_sum >= 0;
}

int main(void) {
	scanf("%lld%lld", &N, &K);

	scores = vector<Data>(N);
	for (Data &d : scores) {
		scanf("%lld%lld", &d.a, &d.b);
	}

	double left = 0, right = 1;
	double result = 0;

	while (left + 0.000000001 < right) {
		const double mid = (left + right) / 2;
		if (parametric_search(mid)) {
			result = max(result, mid);
			left = mid;
		}
		else {
			right = mid;
		}
	}

	printf("%.6lf", (double)result);

	return 0;
}