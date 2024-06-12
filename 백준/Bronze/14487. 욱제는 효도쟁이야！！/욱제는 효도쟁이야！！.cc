#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int max_value = 0;
	int result = 0;
	for (int i = 0; i < N; ++i) {
		int cost;
		scanf("%d", &cost);

		max_value = max(max_value, cost);
		result += cost;
	}

	result -= max_value;

	printf("%d\n", result);

	return 0;
}