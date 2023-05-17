#include <cstdio>

using namespace std;

int main(void) {
	int s, m, l;
	scanf("%d%d%d", &s, &m, &l);

	if (s + 2 * m + 3 * l >= 10) {
		printf("happy\n");
	}
	else {
		printf("sad\n");
	}

	return 0;
}