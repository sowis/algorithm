#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int max_block(vector<int> cuts, const int paper_size) {
	if (cuts.empty()) {
		return paper_size;
	}

	sort(cuts.begin(), cuts.end());
	int result = cuts[0];

	for (int i = 1; i < cuts.size(); ++i) {
		result = max(result, cuts[i] - cuts[i - 1]);
	}

	result = max(result, paper_size - cuts[cuts.size() - 1]);
	return result;
}

int main(void) {
	int width, height;
	scanf("%d%d", &width, &height);

	int count;
	scanf("%d", &count);

	vector<int> width_cuts, height_cuts;
	for (int i = 0; i < count; ++i) {
		int direction, offset;
		scanf("%d%d", &direction, &offset);

		if (direction == 0) {
			height_cuts.push_back(offset);
		}
		else {
			width_cuts.push_back(offset);
		}
	}

	const int result = max_block(width_cuts, width) * max_block(height_cuts, height);
	printf("%d\n", result);

	return 0;
}