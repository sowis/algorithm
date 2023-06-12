#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int length;
		scanf("%d", &length);

		for (int k = 0; k < length; ++k) {
			printf("=");
		}

		printf("\n");
	}

	return 0;
}