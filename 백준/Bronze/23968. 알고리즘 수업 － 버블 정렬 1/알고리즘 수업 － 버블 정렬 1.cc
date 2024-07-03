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

	int count = 0;
	for (int last = N - 1; last > 0; --last) {
		for (int i = 0; i < last; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				++count;

				if (count == K) {
					printf("%d %d\n", min(arr[i], arr[i + 1]), max(arr[i], arr[i + 1]));
					return 0;
				}
			}
		}
	}

	printf("-1\n");

	return 0;
}