#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);

	for (int i = 1; i <= min(a, b); ++i) {
		if (a % i || b % i) {
			continue;
		}

		printf("%d %d %d\n", i, a / i, b / i);
	}

	return 0;
}