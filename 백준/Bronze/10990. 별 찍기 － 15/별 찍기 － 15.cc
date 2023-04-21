#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int y = 1; y <= N; ++y) {
		for (int i = 0; i < N - y; ++i) {
			printf(" ");
		}

		printf("*");

		for (int i = 0; i < 2 * (y -1) - 1; ++i) {
			printf(" ");
		}

		if (y != 1) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}