#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int offset = 1000001;
constexpr long long DIV = 1000000000;

long long fibo[2000003];

int main(void) {
	fibo[0 + offset] = 0;
	fibo[1 + offset] = 1;

	for (int i = 2; i < 1000001; ++i) {
		fibo[i + offset] = fibo[i + offset - 2] + fibo[i + offset - 1];
		fibo[i + offset] %= DIV;
	}

	for (int i = -1; i > -1000001; --i) {
		fibo[i + offset] = fibo[i + offset + 2] - fibo[i + offset + 1];
		fibo[i + offset] %= DIV;
	}

	int input;
	scanf("%d", &input);

	if (fibo[input + offset] > 0) {
		printf("1\n");
	}
	else if (fibo[input + offset] < 0) {
		printf("-1\n");
	}
	else {
		printf("0\n");
	}

	printf("%lld\n", abs(fibo[input + offset]));

	return 0;
}