#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, C;
	scanf("%d%d", &N, &C);

	unordered_set<int> booms;
	for (int i = 0; i < N; ++i) {
		int boom;
		scanf("%d", &boom);

		booms.insert(boom);
	}

	vector<bool> timer(C + 1, false);
	for (const int boom : booms) {
		for (int mul = 1; boom * mul <= C; ++mul) {
			timer[boom * mul] = true;
		}
	}

	int result = 0;
	for (const bool t : timer) {
		if (t) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}