#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	long long n;
	scanf("%lld", &n);

	const long long half = (long long)floor(sqrt(n));

	if (half * half >= n) {
		printf("%lld\n", half);
	}
	else {
		printf("%lld\n", half + 1);
	}

	return 0;
}