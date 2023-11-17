#include <cstdio>

int main(void) {
	int n, u, l;
	scanf("%d%d%d", &n, &u, &l);

	if (n >= 1000 && (u >= 8000 || l >= 260)) {
		printf("Very Good\n");
	}
	else if (n >= 1000) {
		printf("Good\n");
	}
	else {
		printf("Bad\n");
	}

	return 0;
}