#include <cstdio>

using namespace std;

int cows[11];
bool init[11];

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;

	for (int i = 0; i < N; ++i) {
		int cow, position;
		scanf("%d%d", &cow, &position);

		if (init[cow] == false) {
			init[cow] = true;
			cows[cow] = position;
			continue;
		}
		
		if (cows[cow] != position) {
			cows[cow] = position;
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}