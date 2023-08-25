#include <cstdio>
#include <algorithm>

using namespace std;

void test_case(void) {
	int sum = 0;
	int min_num = 987654321;
	for (int i = 0; i < 7; ++i) {
		int num;
		scanf("%d", &num);

		if (num % 2) {
			continue;
		}

		sum += num;
		min_num = min(min_num, num);
	}

	printf("%d %d\n", sum, min_num);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}