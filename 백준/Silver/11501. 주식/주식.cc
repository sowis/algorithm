#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	vector<long long> prices(N);
	for (long long &p : prices) {
		scanf("%lld", &p);
	}

	vector<long long> next_max(N);
	next_max[N - 1] = 0;
	for (int i = N - 2; i >= 0; --i) {
		next_max[i] = max(next_max[i + 1], prices[i + 1]);
	}

	int cur_count = 0;
	long long earn = 0;
	for (int i = 0; i < N; ++i) {
		if (prices[i] < next_max[i]) {
			++cur_count;
			earn -= prices[i];
		}
		else {
			earn += cur_count * prices[i];
			cur_count = 0;
		}
	}

	printf("%lld\n", earn);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}