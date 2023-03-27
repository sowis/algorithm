#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> trees(N);
	for (int &tree : trees) {
		scanf("%d", &tree);
	}

	sort(trees.begin(), trees.end(), greater<>());
	
	int result = 0;
	for (int day = 0; day < N; ++day) {
		result = max(result, trees[day] + day + 2);
	}

	printf("%d\n", result);

	return 0;
}