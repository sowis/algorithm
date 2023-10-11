#include <cstdio>

using namespace std;

int main(void) {
	while (true) {
		long long input;
		scanf("%lld", &input);

		if (input == 0) {
			break;
		}

		const long long result = input * (input + 1) / 2;
		printf("%lld\n", result);
	}

	return 0;
}