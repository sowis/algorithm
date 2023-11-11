#include <cstdio>

using namespace std;

int change_sum(int num, const int notation) {
	int result = 0;
	while (num > 0) {
		result += (num % notation);
		num /= notation;
	}

	return result;
}

int main(void) {
	for (int target = 1000; target < 10000; ++target) {
		const int sum = change_sum(target, 10);
		if (sum != change_sum(target, 12)) {
			continue;
		}

		if (sum != change_sum(target, 16)) {
			continue;
		}

		printf("%d\n", target);
	}

	return 0;
}