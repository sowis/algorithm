#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int A, B, C, X, Y;
	scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);

	if (2 * C < A + B) {
		const int half = min(X, Y) * 2;
		const int a = X - half / 2;
		const int b = Y - half / 2;

		const int fit = a * A + b * B + half * C;
		const int loose = C * max(X, Y) * 2;
		printf("%d\n", min(fit, loose));
	}
	else {
		printf("%d\n", A * X + B * Y);
	}

	return 0;
}