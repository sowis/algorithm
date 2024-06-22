#include <cstdio>

using namespace std;

int main(void) {
	int Q;
	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i) {
		long long a, b;
		scanf("%lld%lld", &a, &b);

		if (2 * a > b) {
			printf("0\n");
			continue;
		}

		if (b % a) {
			printf("0\n");
			continue;
		}

		printf("1\n");
	}

	return 0;
}