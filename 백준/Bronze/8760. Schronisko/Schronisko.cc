#include <cstdio>

using namespace std;

int main(void) {
	int Z;
	scanf("%d", &Z);
	
	for (int i = 0; i < Z; ++i) {
		int W, K;
		scanf("%d%d", &W, &K);

		printf("%d\n", W * K / 2);
	}

	return 0;
}