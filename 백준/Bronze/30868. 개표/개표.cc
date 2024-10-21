#include <cstdio>

void draw(const int vote_count) {
	for (int i = 0; i < vote_count / 5; ++i) {
		printf("++++ ");
	}

	for (int i = 0; i < vote_count % 5; ++i) {
		printf("|");
	}

	printf("\n");
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int vote_count;
		scanf("%d", &vote_count);

		draw(vote_count);
	}

	return 0;
}