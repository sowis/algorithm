#include <cstdio>

const int v1[] = { 1, 2, 3, 3, 4, 10 };
const int v2[] = { 1, 2, 2, 2, 3, 5, 10 };

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int score_1 = 0;
		for (int k = 0; k < 6; ++k) {
			int exist;
			scanf("%d", &exist);

			score_1 += exist * v1[k];
		}

		int score_2 = 0;
		for (int k = 0; k < 7; ++k) {
			int exist;
			scanf("%d", &exist);

			score_2 += exist * v2[k];
		}

		printf("Battle %d: ", i + 1);

		if (score_1 > score_2) {
			printf("Good triumphs over Evil\n");
		}
		else if (score_1 < score_2) {
			printf("Evil eradicates all trace of Good\n");
		}
		else {
			printf("No victor on this battle field\n");
		}
	}

	return 0;
}