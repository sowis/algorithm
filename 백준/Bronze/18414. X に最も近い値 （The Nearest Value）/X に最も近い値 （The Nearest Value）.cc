#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int X, L, R;
	scanf("%d%d%d", &X, &L, &R);

	if (R < X) {
		printf("%d\n", R);
	}
	else if (X < L) {
		printf("%d\n", L);
	}
	else {
		printf("%d\n", X);
	}

	return 0;
}