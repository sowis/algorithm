#include <cstdio>
#include <queue>

using namespace std;

void test_case(void) {
	int K;
	scanf("%d", &K);

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < K; ++i) {
		long long cost;
		scanf("%lld", &cost);

		pq.push(cost);
	}

	long long result = 0;
	while (pq.size() > 1) {
		const long long a = pq.top();
		pq.pop();
		const long long b = pq.top();
		pq.pop();

		pq.push(a + b);
		result += a + b;
	}

	printf("%lld\n", result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}