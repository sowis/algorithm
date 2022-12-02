#include <cstdio>
#include <vector>

using namespace std;

int get_empty_index(const int idx, const vector<int> &v) {
	int count = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != -1) {
			continue;
		}

		++count;
		if (count == idx) {
			return i;
		}
	}

	return -1;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> order(N, -1);
	for (int i = 0; i < N; ++i) {
		int target;
		scanf("%d", &target);

		const int empty_index = get_empty_index(target + 1, order);
		order[empty_index] = i + 1;
	}

	for (const int result : order) {
		printf("%d ", result);
	}


	return 0;
}