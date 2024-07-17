#include <cstdio>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	int min_value = 987654321;
	int max_value = -987654321;

	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);

		min_value = min(min_value, num);
		max_value = max(max_value, num);
	}

	printf("%d %d\n", min_value, max_value);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}