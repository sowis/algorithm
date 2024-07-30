#include <cstdio>

void test_case(void) {
	int d, n, s, p;
	scanf("%d%d%d%d", &d, &n, &s, &p);

	if (n * s == d + n * p) {
		printf("does not matter\n");
	}
	else if (n * s > d + n * p) {
		printf("parallelize\n");
	}
	else {
		printf("do not parallelize\n");
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}