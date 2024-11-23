#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int min_value = 1987654321;
	int result = 0;
	for (int i = 0; i < N; ++i) {
		int cur;
		scanf("%d", &cur);

		min_value = min(min_value, cur);
		result = max(result, cur - min_value);
	}

	printf("%d\n", result);

	return 0;
}