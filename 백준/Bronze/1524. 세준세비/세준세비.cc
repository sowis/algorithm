#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int max_value = 0;
	unordered_map<int, int> a_counts;
	for (int i = 0; i < N; ++i) {
		int value;
		scanf("%d", &value);

		max_value = max(max_value, value);
		++a_counts[value];
	}

	unordered_map<int, int> b_counts;
	for (int i = 0; i < M; ++i) {
		int value;
		scanf("%d", &value);

		max_value = max(max_value, value);
		++b_counts[value];
	}

	const int a_max_count = a_counts[max_value];
	const int b_max_count = b_counts[max_value];

	if (a_max_count >= b_max_count) {
		printf("S\n");
	}
	else {
		printf("B\n");
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}