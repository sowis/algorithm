#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) {
		swap(a, b);
	}

	while (b > 0) {
		const long long remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		long long a, b;
		scanf("%lld%lld", &a, &b);

		const long long lcm = (a / gcd(a, b)) * b;
		printf("%lld\n", lcm);
	}

	return 0;
}