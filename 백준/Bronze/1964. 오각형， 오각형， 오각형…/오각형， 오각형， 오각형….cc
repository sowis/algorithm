#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 5;
	int add = 3;
	
	for (int i = 1; i < N; ++i) {
		result += add;
		result %= 45678;
		result += add - 1;
		result %= 45678;
		result += add - 1;
		result %= 45678;
		++add;
	}

	printf("%d\n", result);

	return 0;
}