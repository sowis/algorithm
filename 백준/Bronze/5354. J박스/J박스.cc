#include <cstdio>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int s;
		scanf("%d", &s);

		if (s != 1) {
			for (int x = 0; x < s; ++x) {
				printf("#");
			}

			printf("\n");
		}

		for (int y = 0; y < s - 2; ++y) {
			printf("#");

			for (int x = 0; x < s - 2; ++x) {
				printf("J");
			}

			printf("#\n");
		}

		for (int x = 0; x < s; ++x) {
			printf("#");
		}

		printf("\n\n");
	}

	return 0;
}