#include <cstdio>

using namespace std;

void test_case(void) {
	int d;
	scanf("%d", &d);

	for (int i = 1; ; ++i) {
		if (i + i * i > d) {
			printf("%d\n", i - 1);
			return;
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}