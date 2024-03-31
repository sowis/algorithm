#include <cstdio>
#include <vector>

using namespace std;

int N, K;

int solve(const vector<int>& arr, vector<bool>& visit, const int weight, const int count) {
	if (weight < 500) {
		return 0;
	}

	if (count == N) {
		return 1;
	}

	int result = 0;
	for (int i = 0; i < N; ++i) {
		if (visit[i]) {
			continue;
		}

		visit[i] = true;
		result += solve(arr, visit, weight - K + arr[i], count + 1);
		visit[i] = false;
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &K);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	vector<bool> visit(N, false);
	const int result = solve(arr, visit, 500, 1);

	printf("%d\n", result);

	return 0;
}