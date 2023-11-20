#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> nums(N);
	for (int& num : nums) {
		scanf("%d", &num);
	}

	sort(nums.begin(), nums.end());

	int cur = 1;
	for (const int num : nums) {
		if (cur != num) {
			break;
		}

		++cur;
	}

	printf("%d\n", cur);

	return 0;
}