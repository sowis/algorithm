#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	int odd_count = 0;
	int odd_min = 987654321;

	for (int i = 0; i < N; ++i) {
		int candy;
		scanf("%d", &candy);

		result += candy;

		if (candy % 2) {
			++odd_count;
			odd_min = min(odd_min, candy);
		}
	}

	if (odd_count % 2) {
		result -= odd_min;
	}

	printf("%d\n", result);

	return 0;
}