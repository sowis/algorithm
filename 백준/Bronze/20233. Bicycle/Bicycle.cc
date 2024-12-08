#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int a, x, b, y;
	scanf("%d%d%d%d", &a, &x, &b, &y);

	int T;
	scanf("%d\n", &T);

	const int r1 = max(0, T - 30) * x * 21 + a;
	const int r2 = max(0, T - 45) * y * 21 + b;

	printf("%d %d\n", r1, r2);

	return 0;
}