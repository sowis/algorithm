#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(void) {
	long long N;
	scanf("%lld", &N);
	
	vector<long long> houses(N);
	for (long long& house : houses) {
		scanf("%lld", &house);
	}

	sort(houses.begin(), houses.end());
	if (N % 2) {
		printf("%lld\n", houses[N / 2]);
	}
	else {
		printf("%lld\n", houses[N / 2 - 1]);
	}

	return 0;
}