#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int y = 1; y <= N; ++y) {
		for (int x = 0; x < N; ++x) {
			printf("* ");
		}

		printf("\n");

		++y;
		if (y > N) {
			break;
		}

		printf(" ");
		for (int x = 0; x < N; ++x) {
			printf("* ");
		}

		printf("\n");
	}

	return 0;
}