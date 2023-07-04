#include <cstdio>

using namespace std;

int main(void) {
	int a1, a0, c, n0;
	scanf("%d%d%d%d", &a1, &a0, &c, &n0);

	if (a1 > c) {
		printf("0\n");
		return 0;
	}

	if (a1 * n0 + a0 <= c * n0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}

	return 0;
}