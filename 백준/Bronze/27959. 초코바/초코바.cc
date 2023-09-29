#include <cstdio>

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	if (100 * N >= M) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}