#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N * N);
	for (int& number : arr) {
		scanf("%d", &number);
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	printf("%d\n", arr[N - 1]);

	return 0;
}