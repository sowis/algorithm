#include <cstdio>

using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);

	int jump_count = 0;

	while (true) {
		const int interval_1 = B - A;
		const int interval_2 = C - B;

		if (interval_1 == 1 && interval_2 == 1) {
			break;
		}

		if (interval_1 > interval_2) {
			C = B;
			--B;
		}
		else {
			A = B;
			++B;
		}

		++jump_count;
	}

	printf("%d\n", jump_count);

	return 0;
}