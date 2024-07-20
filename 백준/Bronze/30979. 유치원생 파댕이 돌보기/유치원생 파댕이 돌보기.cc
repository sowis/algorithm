#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	int N;
	scanf("%d", &N);

	int sums = 0;
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);

		sums += num;
	}

	if (T <= sums) {
		printf("Padaeng_i Happy");
	}
	else {
		printf("Padaeng_i Cry");
	}

	return 0;
}