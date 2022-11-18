#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N - (y + 1); ++x) {
			printf(" ");
		}

		for (int star = 0; star < y + 1; ++star) {
			printf("* ");
		}

		printf("\n");
	}

	return 0;
}