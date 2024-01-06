#include <cstdio>

using namespace std;

int main(void) {
	int N;
	int result = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		result += input;
	}

	result += 8 * (N - 1);

	printf("%d %d\n", result / 24, result % 24);

	return 0;
}