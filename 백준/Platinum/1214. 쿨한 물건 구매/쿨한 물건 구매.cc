#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	long long D, P, Q;
	scanf("%lld%lld%lld", &D, &P, &Q);

	if (P > Q) {
		swap(P, Q);
	}

	long long q_count = D / Q + ((D % Q) ? 1 : 0);
	long long min_cost = q_count * Q;

	for (q_count = 0; q_count <= min(D / Q, P); ++q_count) {
		const long long remain = D - q_count * Q;
		const long long p_count = remain / P + ((remain % P) ? 1 : 0);
		const long long value = p_count * P + q_count * Q;
		min_cost = min(min_cost, value);
	}

	printf("%lld\n", min_cost);

	return 0;
}