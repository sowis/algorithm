#include <cstdio>

int main(void) {
	int num;
	scanf("%d\n", &num);

	if (num >= 620) {
		printf("Red\n");
	}
	else if (num >= 590) {
		printf("Orange\n");
	}
	else if (num >= 570) {
		printf("Yellow\n");
	}
	else if (num >= 495) {
		printf("Green\n");
	}
	else if (num >= 450) {
		printf("Blue\n");
	}
	else if (num >= 425) {
		printf("Indigo\n");
	}
	else if (num >= 380) {
		printf("Violet\n");
	}

	return 0;
}