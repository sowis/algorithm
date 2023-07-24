#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	long long a, b;
	scanf("%lld%lld", &a, &b);

	if (a > b) {
		swap(a, b);
	}

	if (a == b) {
		printf("0\n");
		return 0;
	}

	printf("%lld\n", b - a - 1);

	for (long long i = a + 1; i < b; ++i) {
		printf("%lld ", i);
	}

	return 0;
}