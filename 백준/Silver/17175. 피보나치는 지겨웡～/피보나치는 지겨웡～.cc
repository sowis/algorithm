#include <cstdio>

constexpr int DIV = 1000000007;

int count[51];

int fibo(const int N) {
	if (count[N] != 0) {
		return count[N];
	}

	if (N < 2) {
		return count[N] =1;
	}

	return count[N] = (fibo(N - 2) + fibo(N - 1) + 1) % DIV;
}

int main(void) {
	int N;
	scanf("%d", &N);

	printf("%d\n", fibo(N));

	return 0;
}