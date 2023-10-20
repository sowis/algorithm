#include <cstdio>

void draw(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < i; ++k) {
			printf("*");
		}

		printf("\n");
	}
}

int main(void) {
	while (true) {
		int input;
		scanf("%d", &input);

		if (input == 0) {
			break;
		}

		draw(input);
	}

	return 0;
}