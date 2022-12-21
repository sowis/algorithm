#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	vector<int> arr(10);
	for (int i = 0; i < T; ++i) {
		for (int k = 0; k < 10; ++k) {
			scanf("%d", &arr[k]);
		}

		sort(arr.begin(), arr.end());

		printf("%d\n", arr[7]);
	}

	return 0;
}