#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	sort(arr.begin(), arr.end());

	long long result = 0;
	for (int i = 0; i < N; ++i) {
		result += abs(arr[i] - (i + 1));
	}

	printf("%lld\n", result);

	return 0;
}