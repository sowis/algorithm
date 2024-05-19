#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	vector<int> counts(200001, 0);
	int result = 0;
	int begin = 0;
	for (int end = 0; end < N; ++end) {
		if (counts[arr[end]] < K) {
			++counts[arr[end]];
			result = max(result, end - begin + 1);
		}
		else {
			while (arr[begin] != arr[end]) {
				--counts[arr[begin]];
				++begin;
			}

			++begin;
			result = max(result, end - begin + 1);
		}
	}

	printf("%d\n", result);

	return 0;
}