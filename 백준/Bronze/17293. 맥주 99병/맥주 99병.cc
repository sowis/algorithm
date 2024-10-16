#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = N; i > 2; --i) {
		printf("%d bottles of beer on the wall, %d bottles of beer.\n\
Take one down and pass it around, %d bottles of beer on the wall.\n\n", i, i, i - 1);
	}

	if (N >= 2) {
		printf("2 bottles of beer on the wall, 2 bottles of beer.\n\
Take one down and pass it around, 1 bottle of beer on the wall.\n\n");
	}

	printf("1 bottle of beer on the wall, 1 bottle of beer.\n\
Take one down and pass it around, no more bottles of beer on the wall.\n\n");

	if (N == 1) {
		printf("No more bottles of beer on the wall, no more bottles of beer.\n\
Go to the store and buy some more, %d bottle of beer on the wall.\n\n", N);
	}
	else {
		printf("No more bottles of beer on the wall, no more bottles of beer.\n\
Go to the store and buy some more, %d bottles of beer on the wall.\n\n", N);
	}

	return 0;
}