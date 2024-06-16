#include <cstdio>
#include <vector>

using namespace std;

vector<long long> sums(80001, 0);

int main(void) {
	long long all_sum = 0;
	for (int i = 3; i < 80001; ++i) {
		if (i % 3 == 0 || i % 7 == 0) {
			all_sum += i;
		}

		sums[i] = all_sum;
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		printf("%lld\n", sums[N]);
	}

	return 0;
}