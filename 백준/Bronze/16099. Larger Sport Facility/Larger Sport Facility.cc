#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		long long a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

		if ((a * b) < (c * d)) {
			printf("Eurecom\n");
		}
		else if (a * b > c * d) {
			printf("TelecomParisTech\n");
		}
		else {
			printf("Tie\n");
		}
	}

	return 0;
}