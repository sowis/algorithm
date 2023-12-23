#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}

	while (b > 0) {
		const int remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main(void) {
	while (true) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a == 0 && b == 0) {
			break;
		}

		const int out = a / b;
		a %= b;
		const int g = gcd(a, b);

		printf("%d ", out);
		printf("%d / %d\n", a, b);
	}

	return 0;
}