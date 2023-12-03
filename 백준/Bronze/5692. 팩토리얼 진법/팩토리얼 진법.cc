#include <cstdio>

using namespace std;

int factorial[] = { 1, 2, 6, 24, 120 };

int main(void) {
	while (true) {
		int input;
		scanf("%d", &input);

		if (input == 0) {
			break;
		}

		int result = 0;
		int index = 0;
		while (input > 0) {
			result += (input % 10) * factorial[index];
			++index;
			input /= 10;
		}

		printf("%d\n", result);
	}

	return 0;
}