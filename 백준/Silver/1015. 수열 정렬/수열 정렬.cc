#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	vector<bool> use(N, false);

	for (int& number : arr) {
		scanf("%d", &number);
	}

	vector<int> original(arr);
	sort(arr.begin(), arr.end());

	vector<int> result;
	for (const int target : original) {
		for (int i = 0; i < N; ++i) {
			if (target != arr[i]) {
				continue;
			}

			if (use[i] == true) {
				continue;
			}

			result.push_back(i);
			use[i] = true;
			break;
		}
	}

	for (const int r : result) {
		printf("%d ", r);
	}

	return 0;
}
