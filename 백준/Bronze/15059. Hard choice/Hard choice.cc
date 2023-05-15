#include <cstdio>

using namespace std;

int main(void) {
	int arr[2][3];

	for (int i = 0; i < 2; ++i) {
		for (int k = 0; k < 3; ++k) {
			scanf("%d", &arr[i][k]);
		}
	}

	int result = 0;
	for (int i = 0; i < 3; ++i) {
		if (arr[0][i] >= arr[1][i]) {
			continue;
		}

		result += arr[1][i] - arr[0][i];
	}

	printf("%d\n", result);

	return 0;
}