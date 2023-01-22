#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	if (b > a) {
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
	long long A, B;
	scanf("%lld%lld", &A, &B);

	const long long result = A / gcd(A, B) * B;

	printf("%lld\n", result);

	return 0;
}