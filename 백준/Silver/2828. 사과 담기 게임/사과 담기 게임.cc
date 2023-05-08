#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int j;
	scanf("%d", &j);

	int left = 1;
	int right = M;
	int result = 0;

	for (int i = 0; i < j; ++i) {
		int apple;
		scanf("%d", &apple);

		int move = 0;

		if (left <= apple && apple <= right) {
			continue;
		}
		else if (apple < left) {
			move = apple - left;
		}
		else if (right < apple) {
			move = apple - right;
		}

		left += move;
		right += move;
		result += abs(move);
	}

	printf("%d\n", result);

	return 0;
}