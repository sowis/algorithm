#include <cstdio>

using namespace std;

char directions[4] = { 'N', 'E', 'S', 'W' };

int main(void) {
	int cur = 0;

	for (int i = 0; i < 10; ++i) {
		int input;
		scanf("%d", &input);

		if (input == 1) {
			cur += 1;
			cur %= 4;
		}
		else if (input == 2) {
			cur += 2;
			cur %= 4;
		}
		else {
			cur += 3;
			cur %= 4;
		}
	}

	printf("%c", directions[cur]);

	return 0;
}