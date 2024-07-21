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

	int swap_count = 0;
	for (int last = N - 1; last >= 1; --last) {
		int max_index = -1;
		int max_value = 0;

		for (int i = 0; i <= last; ++i) {
			if (v[i] > max_value) {
				max_value = v[i];
				max_index = i;
			}
		}

		if (last != max_index) {
			swap(v[last], v[max_index]);
			++swap_count;

			if (swap_count == K) {
				for (const int num : v) {
					printf("%d ", num);
				}

				return 0;
			}
		}
	}

	printf("-1\n");

	return 0;
}