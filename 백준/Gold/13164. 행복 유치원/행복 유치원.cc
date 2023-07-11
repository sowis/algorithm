#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> heights(N);
	for (int& height : heights) {
		scanf("%d", &height);
	}

	vector<int> height_diffs;
	for (int i = 1; i < N; ++i) {
		height_diffs.push_back(heights[i] - heights[i - 1]);
	}

	sort(height_diffs.begin(), height_diffs.end());

	int result = 0;
	for (int i = 0; i < height_diffs.size() - K + 1; ++i) {
		result += height_diffs[i];
	}

	printf("%d\n", result);

	return 0;
}