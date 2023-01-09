#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int current;
	int last;
	int low;

	scanf("%d", &current);
	last = low = current;

	int result = 0;
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d", &current);

		if (current <= last) {
			low = current;
		}
		else {
			result = max(result, current - low);
		}

		last = current;
	}

	printf("%d\n", result);

	return 0;
}