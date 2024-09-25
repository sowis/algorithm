#include <cstdio>

int main(void) {
	int cur = -1;
	bool up = true;

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		if (input > cur) {
			if (up == false) {
				printf("NO\n");
				return 0;
			}

			cur = input;
		}
		else if (input < cur) {
			up = false;
			cur = input;
		}
		else {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}