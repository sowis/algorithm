#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int &num : arr) {
		scanf("%d", &num);
	}

	int high = arr[N - 1] + 1;
	int result = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (arr[i] >= high) {
			result += arr[i] - high + 1;
			high = high - 1;
		}
		else {
			high = arr[i];
		}
	}

	printf("%d\n", result);

	return 0;
}