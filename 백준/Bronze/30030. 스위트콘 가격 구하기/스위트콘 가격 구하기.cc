#include <cstdio>

int main(void) {
	int B;
	scanf("%d", &B);

	const int A = (B / 11) * 10;
	printf("%d\n", A);

	return 0;
}