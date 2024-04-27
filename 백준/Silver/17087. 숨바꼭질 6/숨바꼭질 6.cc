#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int small, int big) {
	if (big < small) {
		swap(small, big);
	}

	while (small > 0) {
		const int remain = big % small;
		big = small;
		small = remain;
	}

	return big;
}

int main(void) {
	int N, S;
	scanf("%d%d", &N, &S);

	vector<int> arr(N);
	for (int& n : arr) {
		scanf("%d", &n);

		n = abs(n - S);
	}

	sort(arr.begin(), arr.end());

	int result = arr[0];
	for (int i = 1; i < N; ++i) {
		result = gcd(result, arr[i]);
	}

	printf("%d\n", result);

	return 0;
}