#include <cstdio>
#include <stack>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int target = 1;
	stack<int> stk;

	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		while (stk.empty() == false && stk.top() == target) {
			stk.pop();
			++target;
		}

		if (target == input) {
			++target;
			continue;
		}

		if (input > target) {
			stk.push(input);
		}
		else {
			printf("Sad\n");
			return 0;
		}
	}

	while (stk.empty() == false) {
		if (stk.top() != target) {
			printf("Sad\n");
			return 0;
		}

		stk.pop();
		++target;
	}

	printf("Nice\n");

	return 0;
}