#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int x, y;
	scanf("%d%d", &x, &y);

	if (N == 1) {
		printf("0\n");
		return 0;
	}

	if ((x == 1 || x == N) && (y == 1 || y == N)) {
		printf("2\n");
	}
	else if ((x == 1 || x == N) || (y == 1 || y == N)) {
		printf("3\n");
	}
	else {
		printf("4\n");
	}

	return 0;
}