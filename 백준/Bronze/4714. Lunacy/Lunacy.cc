#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	while (true) {
		double d;
		scanf("%lf", &d);

		if (d + 1 < 0.000001) {
			break;
		}

		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", d, d * 0.167);
	}

	return 0;
}