#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> v(N);
	for (int& num : v) {
		scanf("%d", &num);
	}

	int change = 0;
	for (int last = N - 1; last >= 1; --last) {
		for (int i = 0; i < last; ++i) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				++change;
			}

			if (change == K) {
				for (const int n : v) {
					printf("%d ", n);
				}

				return 0;
			}
		}
	}

	if (change == K) {
		for (const int n : v) {
			printf("%d ", n);
		}

		return 0;
	}
	else {
		printf("-1\n");
	}

	return 0;
}