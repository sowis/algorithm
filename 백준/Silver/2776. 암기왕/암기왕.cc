#include <cstdio>
#include <unordered_set>

using namespace std;

void test_case(void) {
	unordered_set<int> ints;
	
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int number;
		scanf("%d", &number);
		ints.insert(number);
	}

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int target;
		scanf("%d", &target);

		if (ints.find(target) == ints.end()) {
			printf("0\n");
		}
		else {
			printf("1\n");
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}