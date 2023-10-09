#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr(4);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	int result = 0;
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			if (b == a) {
				continue;
			}

			const int width = min(arr[a], arr[b]);
			int height = 987654321;
			for (int c = 0; c < 4; ++c) {
				if (c == a || c == b) {
					continue;
				}

				height = min(height, arr[c]);
			}

			result = max(result, width * height);
		}
	}

	printf("%d\n", result);

	return 0;
}