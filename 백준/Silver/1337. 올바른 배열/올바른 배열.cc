#include <cstdio>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	unordered_set<int> items;
	for (int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);

		items.insert(tmp);
	}

	int result = 4;
	for (const int i : items) {
		int to_add = 0;
		for (int offset = 1; offset <= 4; ++offset) {
			if (items.find(i + offset) == items.end()) {
				++to_add;
			}
		}

		result = min(result, to_add);
	}

	printf("%d\n", result);

	return 0;
}