#include <cstdio>

using namespace std;

int main(void) {
	while (true) {
		int N;
		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		int result = 0;
		for (int sz = 1; sz <= N; ++sz) {
			const int count = N - (sz - 1);
			result += count * count;
		}

		printf("%d\n", result);
	}

	return 0;
}