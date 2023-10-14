#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	int m = 0;

	for (int& num : arr) {
		scanf("%d", &num);
		m = max(m, num);
	}

	for (int i = 1; i <= m; ++i) {
		bool clear = true;
		for (const int num : arr) {
			if (num < i) {
				return 0;
			}

			if (num % i != 0) {
				clear = false;
				break;
			}
		}

		if (clear) {
			printf("%d\n", i);
		}
	}

	return 0;
}