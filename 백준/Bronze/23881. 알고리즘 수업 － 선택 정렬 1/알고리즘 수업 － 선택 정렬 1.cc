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

	int count = 1;
	for (int last = N - 1; last >= 1; --last) {
		int max_index = -1;
		int max_value = -987654321;

		for (int i = 0; i <= last; ++i) {
			if (v[i] > max_value) {
				max_index = i;
				max_value = v[i];
			}
		}

		if (max_index == last) {
			continue;
		}

		if (count == K) {
			printf("%d %d\n", min(max_value, v[last]), max(max_value, v[last]));
			return 0;
		}

		swap(v[max_index], v[last]);
		++count;
	}

	printf("-1\n");

	return 0;
}