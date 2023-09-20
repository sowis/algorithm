#include <cstdio>

using namespace std;

int main(void) {
	int R, C;
	scanf("%d%d", &R, &C);

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}