#include <cstdio>

using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (c % 2) {
		a ^= b;
	}

	printf("%d\n", a);

	return 0;
}