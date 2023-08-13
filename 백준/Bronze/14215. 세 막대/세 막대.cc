#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr(3);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	sort(arr.begin(), arr.end());

	if (arr[2] >= arr[0] + arr[1]) {
		arr[2] = arr[0] + arr[1] - 1;
	}

	const int result = arr[0] + arr[1] + arr[2];
	printf("%d\n", result);

	return 0;
}