#include <cstdio>

char change(const int r, const int g, const int b) {
	const int i = 2126 * r + 7152 * g + 722 * b;
	if (i < 510000) {
		return '#';
	}
	else if (i < 1020000) {
		return 'o';
	}
	else if (i < 1530000) {
		return '+';
	}
	else if (i < 2040000) {
		return '-';
	}
	else {
		return '.';
	}
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int r, g, b;
			scanf("%d%d%d", &r, &g, &b);

			const int i = change(r, g, b);
			printf("%c", i);
		}

		printf("\n");
	}

	return 0;
}