#include <unordered_set>
#include <cstdio>

using namespace std;

int main(void) {
	while (true) {
		int input;
		scanf("%d", &input);

		if (input == -1) {
			break;
		}

		unordered_set<int> s;
		s.insert(input);

		while (true) {
			scanf("%d", &input);
			if (input == 0) {
				break;
			}

			s.insert(input);
		}

		int result = 0;
		for (const int number : s) {
			if (s.find(number * 2) != s.end()) {
				++result;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}