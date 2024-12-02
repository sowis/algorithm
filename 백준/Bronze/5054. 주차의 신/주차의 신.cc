#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	int min_shop = 987654321;
	int max_shop = 0;

	for (int i = 0; i < N; ++i) {
		int shop;
		scanf("%d", &shop);

		min_shop = min(min_shop, shop);
		max_shop = max(max_shop, shop);
	}

	const int result = 2 * (max_shop - min_shop);
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