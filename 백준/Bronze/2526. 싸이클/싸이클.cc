#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	long long N, P;
	scanf("%lld%lld", &N, &P);

	vector<long long> cache(1001, -1);

	long long current = N;
	long long order = 1;

	while (cache[current] == -1) {
		cache[current] = order;
		++order;
		current *= N;
		current %= P;
	}

	printf("%lld\n", order - cache[current]);

	return 0;
}