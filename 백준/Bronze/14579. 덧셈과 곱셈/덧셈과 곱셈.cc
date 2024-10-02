#include <cstdio>

constexpr int DIV = 14579;

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);

	int result = 1;
	for (int cur = a; cur <= b; ++cur) {
		const int sum = (cur * (cur + 1) / 2) % DIV;
		result = (result * sum) % DIV;
	}

	printf("%d\n", result);

	return 0;
}