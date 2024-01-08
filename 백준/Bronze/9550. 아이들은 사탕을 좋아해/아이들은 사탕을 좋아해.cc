#include <cstdio>

using namespace std;

void test_case(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int candy;
		scanf("%d", &candy);

		result += candy / K;
	}

	printf("%d\n", result);
}



int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}