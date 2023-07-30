#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	vector<int> logs(N);
	for (int& log : logs) {
		scanf("%d", &log);
	}

	sort(logs.begin(), logs.end());
	vector<int> results(N);
	int left = 0;
	int right = N - 1;
	bool is_left = true;

	for (const int log : logs) {
		if (is_left) {
			results[left] = log;
			++left;
		}
		else {
			results[right] = log;
			--right;
		}

		is_left = !is_left;
	}

	int result = numeric_limits<int>::min();
	for (int i = 1; i < N; ++i) {
		result = max(result, abs(results[i] - results[i - 1]));
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