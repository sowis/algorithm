#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	int result = numeric_limits<int>::min();
	for (int begin = 0; begin < N; ++begin) {
		int subsum = 0;
		for (int target = begin; target < N; ++target) {
			subsum += arr[target];
			result = max(result, subsum);
		}
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