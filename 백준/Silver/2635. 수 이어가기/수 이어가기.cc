#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> result;
	
	for (int i = 1; i <= N + 1; ++i) {
		vector<int> current_array{ N, i };
		int next = N - i;

		while (next >= 0) {
			current_array.push_back(next);
			next = current_array[current_array.size() - 2] - current_array[current_array.size() - 1];
		}

		if (current_array.size() > result.size()) {
			result = current_array;
		}
	}

	printf("%zd\n", result.size());
	for (const int r : result) {
		printf("%d ", r);
	}

	return 0;
}