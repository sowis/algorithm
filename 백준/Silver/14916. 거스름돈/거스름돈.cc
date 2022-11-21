#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int coin_two = 0; coin_two * 2 <= N; ++coin_two) {
		if ((N - coin_two * 2) % 5) {
			continue;
		}

		const int coin_five = (N - coin_two * 2) / 5;
		printf("%d\n", coin_two + coin_five);
		return 0;
	}

	printf("-1\n");

	return 0;
}