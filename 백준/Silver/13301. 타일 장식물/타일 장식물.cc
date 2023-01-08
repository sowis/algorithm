#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<long long> cache(81);
	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i < cache.size(); ++i) {
		cache[i] = cache[i - 2] + cache[i - 1];
	}

	int N;
	scanf("%d", &N);

	const long long result = 2 * (2 * cache[N] + cache[N - 1]);
	printf("%lld\n", result);

	return 0;
}