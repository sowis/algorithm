#include <cstdio>

int main(void) {
	int a = 0, b = 0;

	for (int i = 0; i < 3; ++i) {
		int input;
		scanf("%d", &input);

		if (input == 1) {
			++a;
		}
		else {
			++b;
		}
	}

	if (a > b) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}

	return 0;
}