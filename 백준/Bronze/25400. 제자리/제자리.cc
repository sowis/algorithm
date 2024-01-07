#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int target = 1;
	int erase = 0;

	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		if (input == target) {
			++target;
		}
		else {
			++erase;
		}
	}

	printf("%d\n", erase);

	return 0;
}