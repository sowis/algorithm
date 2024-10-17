#include <cstdio>

int grade(const int order, const int all) {
	const int d = order * 100 / all;

	if (d <= 4) {
		return 1;
	}
	else if (d <= 11) {
		return 2;
	}
	else if (d <= 23) {
		return 3;
	}
	else if (d <= 40) {
		return 4;
	}
	else if (d <= 60) {
		return 5;
	}
	else if (d <= 77) {
		return 6;
	}
	else if (d <= 89) {
		return 7;
	}
	else if (d <= 96) {
		return 8;
	}
	else {
		return 9;
	}
}

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	for (int i = 0; i < K; ++i) {
		int score;
		scanf("%d", &score);

		printf("%d ", grade(score, N));
	}

	return 0;
}