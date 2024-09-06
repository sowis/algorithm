#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int num;
		scanf("%d", &num);

		if ((num + 1) % (num % 100) == 0) {
			printf("Good\n");
		}
		else {
			printf("Bye\n");
		}
	}

	return 0;
}