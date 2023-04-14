#include <cstdio>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);

	const int target = b - a;
	if (1 <= target && target <= 20) {
		printf("You are speeding and your fine is $100.\n");
	}
	else if (21 <= target && target <= 30) {
		printf("You are speeding and your fine is $270.\n");
	}
	else if (31 <= target) {
		printf("You are speeding and your fine is $500.\n");
	}
	else {
		printf("Congratulations, you are within the speed limit!");
	}

	return 0;
}