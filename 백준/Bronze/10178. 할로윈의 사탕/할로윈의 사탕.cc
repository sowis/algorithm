#include <cstdio>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a % b);
	}

	return 0;
}