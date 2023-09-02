#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}

	while (b > 0) {
		const int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		const int g = gcd(a, b);
		printf("%d %d\n", a * b / g, g);
	}

	return 0;
}