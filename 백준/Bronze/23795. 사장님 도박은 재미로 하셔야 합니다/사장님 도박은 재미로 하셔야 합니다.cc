#include <cstdio>

using namespace std;

int main(void) {
	int input;
	scanf("%d", &input);

	int result = 0;
	while (input != -1) {
		result += input;
		scanf("%d", &input);
	}

	printf("%d\n", result);

	return 0;
}