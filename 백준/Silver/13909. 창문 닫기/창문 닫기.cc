#include <cstdio>

int main(void) {
	long long input;
	scanf("%lld", &input);

	long long last = 1;
	long long ok = 1;
	while (true) {
		if (last * last > input) {
			break;
		}
		else {
			ok = last;
		}

		++last;
	}

	printf("%lld\n", ok);

	return 0;
}