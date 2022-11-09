#include <cstdio>
#include <cmath>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> cache;

long long Ai(const long long i) {
	if (cache.find(i) != cache.end()) {
		return cache[i];
	}

	return cache[i] = Ai((long long)floor(i / P)) + Ai((long long)floor(i / Q));
}

int main(void) {
	cache[0] = 1;

	scanf("%lld%lld%lld", &N, &P, &Q);

	printf("%lld\n", Ai(N));

	return 0;
}