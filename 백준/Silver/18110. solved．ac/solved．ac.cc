#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	if (N == 0) {
		printf("0\n");
		return 0;
	}

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	sort(arr.begin(), arr.end());

	const int r = (int)round(N * 0.15);
	long long s = 0;
	for (int i = r; i < N - r; ++i) {
		s += arr[i];
	}

	const long long result = (long long)round(s / (double)(N - 2 * r));
	printf("%lld\n", result);

	return 0;
}