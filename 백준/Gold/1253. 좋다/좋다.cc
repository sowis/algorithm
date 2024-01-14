#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int& n : v) {
		scanf("%d", &n);
	}

	sort(v.begin(), v.end());

	int result = 0;

	for (int target_idx = 0; target_idx < N; ++target_idx) {
		int left_idx = 0;
		int right_idx = N - 1;

		while (left_idx < right_idx) {
			if (left_idx == target_idx) {
				++left_idx;
				continue;
			}

			if (right_idx == target_idx) {
				--right_idx;
				continue;
			}

			if (v[left_idx] + v[right_idx] == v[target_idx]) {
				++result;
				break;
			}
			else if (v[left_idx] + v[right_idx] < v[target_idx]) {
				++left_idx;
			}
			else {
				--right_idx;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}