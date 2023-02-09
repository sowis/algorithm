#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int indent = (2 * N - 1) / 2;
	for (int i = 0; i < indent; ++i) {
		printf(" ");
	}

	printf("*\n");
	--indent;

	int space = 1;
	for (int line = 1; line < N - 1; ++line) {
		for (int i = 0; i < indent; ++i) {
			printf(" ");
		}

		printf("*");

		for (int i = 0; i < space; ++i) {
			printf(" ");
		}

		printf("*\n");

		--indent;
		space += 2;
	}

	if (N != 1) {
		for (int i = 0; i < (2 * N - 1); ++i) {
			printf("*");
		}
	}

	return 0;
}