#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> temp(N);
	for (int &t : temp) {
		scanf("%d", &t);
	}

	int current_sum = 0;
	int result = 0;

	for (int i = 0; i < K; ++i) {
		current_sum += temp[i];
	}

	result = current_sum;

	for (int i = K; i < N; ++i) {
		current_sum += temp[i];
		current_sum -= temp[i - K];
		result = max(result, current_sum);
	}

	printf("%d\n", result);

	return 0;
}