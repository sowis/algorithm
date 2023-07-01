#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int cards[20];
	for (int i = 0; i < 20; ++i) {
		cards[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i) {
		int begin, end;
		scanf("%d%d", &begin, &end);

		reverse(cards + begin - 1, cards + end);
	}

	for (int i = 0; i < 20; ++i) {
		printf("%d ", cards[i]);
	}

	return 0;
}