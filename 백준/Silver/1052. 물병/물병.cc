#include <cstdio>

using namespace std;

int upper_2_pow(const int target) {
	int result = 1;

	while (result < target) {
		result *= 2;
	}

	return result;
}

int lower_2_pow(const int target) {
	int result = 1;

	while (result < target) {
		result *= 2;
	}

	if (target == result) {
		return result;
	}
	else {
		return result / 2;
	}
}

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	while (K > 1) {
		if (N <= K) {
			printf("0\n");
			return 0;
		}

		const int lo = lower_2_pow(N);
		N -= lo;
		--K;
	}

	const int result = upper_2_pow(N) - N;
	printf("%d\n", result);

	return 0;
}