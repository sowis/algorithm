#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);

		if (num % 2) {
			printf("%d is odd\n", num);
		}
		else {
			printf("%d is even\n", num);
		}
	}

	return 0;
}