#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers(N);
	for (int& number : numbers) {
		scanf("%d", &number);
	}

	int result;
	int min_diff_sum = numeric_limits<int>::max();
	for (int target = 1; target <= 10000; ++target) {
		int diff_sum = 0;
		for (const int num : numbers) {
			diff_sum += abs(target - num);
		}

		if (diff_sum < min_diff_sum) {
			min_diff_sum = diff_sum;
			result = target;
		}
	}

	printf("%d\n", result);

	return 0;
}