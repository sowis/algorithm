#include <cstdio>

using namespace std;

constexpr int DIV = 1000000007;

int main(void) {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
		return 0;
	}
	else if (n == 1) {
		printf("1\n");
		return 0;
	}

	int last = 0;
	int current = 1;
	int idx = 1;

	while (idx < n) {
		const int next = (last + current) % DIV;
		last = current;
		current = next;
		++idx;
	}

	printf("%d\n", current);

	return 0;
}