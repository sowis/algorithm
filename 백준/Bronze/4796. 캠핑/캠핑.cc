#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	long long L, P, V;

	for (int i = 1 ; ; ++i) {
		scanf("%lld%lld%lld", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0) {
			break;
		}

		const long long result = (V / P) * L + min((V % P), L);
		printf("Case %d: %lld\n", i, result);
	}

	return 0;
}