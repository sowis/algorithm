#include <cstdio>

using namespace std;

void test_case(void) {
	int s;
	scanf("%d", &s);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int q, p;
		scanf("%d%d", &q, &p);

		s += q * p;
	}

	printf("%d\n", s);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}