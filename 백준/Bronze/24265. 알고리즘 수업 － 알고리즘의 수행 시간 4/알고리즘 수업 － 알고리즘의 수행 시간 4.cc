#include <cstdio>

using namespace std;

int main(void) {
	long long n;
	scanf("%lld", &n);

	printf("%lld\n", n * (n - 1) / 2);
	printf("2\n");

	return 0;
}