#include <cstdio>
#include <vector>

using namespace std;

vector<long long> cache(68, -1);

long long koong(const int N) {
	if (cache[N] != -1) {
		return cache[N];
	}

	return cache[N] = koong(N - 1) + koong(N - 2) + koong(N - 3) + koong(N - 4);
}

int main(void) {
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		printf("%lld\n", koong(N));
	}

	return 0;
}