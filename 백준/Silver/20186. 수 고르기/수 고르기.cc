#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> numbers(N);
	for (int& num : numbers) {
		scanf("%d", &num);
	}

	sort(numbers.begin(), numbers.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < K; ++i) {
		result += numbers[i];
	}

	result -= (K * (K - 1)) / 2;
	printf("%d\n", result);

	return 0;
}