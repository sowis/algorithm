#include <cstdio>
#include <vector>

using namespace std;

vector<long long> fx_cache(1000001, 0);
vector<long long> gx_cache(1000001, 0);

void test_case(void) {
	int N;
	scanf("%d", &N);

	printf("%lld\n", gx_cache[N]);
}

int main(void) {
	for (long long i = 1; i <= 1000000; ++i) {
		for (long long k = 1; i * k <= 1000000; ++k) {
			fx_cache[i * k] += i;
		}
	}
	
	long long gx = 0;
	for (int i = 1; i <= 1000000; ++i) {
		gx += fx_cache[i];
		gx_cache[i] = gx;
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}