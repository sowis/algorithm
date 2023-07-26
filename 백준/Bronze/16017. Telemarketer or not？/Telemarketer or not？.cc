#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (a != 8 && a != 9) {
		printf("answer\n");
		return 0;
	}

	if (d != 8 && d != 9) {
		printf("answer\n");
		return 0;
	}

	if (b != c) {
		printf("answer\n");
		return 0;
	}

	printf("ignore\n");

	return 0;
}