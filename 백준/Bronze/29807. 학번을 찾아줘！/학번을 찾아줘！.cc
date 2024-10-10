#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int scores[5] = { 0 };
	for (int i = 0; i < N; ++i) {
		scanf("%d", &scores[i]);
	}

	int result = 0;
	if (scores[0] > scores[2]) {
		result += (scores[0] - scores[2]) * 508;
	}
	else {
		result += (scores[2] - scores[0]) * 108;
	}

	if (scores[1] > scores[3]) {
		result += (scores[1] - scores[3]) * 212;
	}
	else {
		result += (scores[3] - scores[1]) * 305;
	}

	if (N == 5) {
		result += scores[4] * 707;
	}

	result *= 4763;
	printf("%d\n", result);

	return 0;
}