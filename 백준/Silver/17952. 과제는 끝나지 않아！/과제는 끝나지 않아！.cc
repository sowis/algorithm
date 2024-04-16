#include <cstdio>
#include <stack>

using namespace std;

typedef struct _data {
	int score;
	int remain;
} Data;

int main(void) {
	int N;
	scanf("%d", &N);

	stack<Data> stk;
	int result = 0;
	Data current{ -1, -1 };

	for (int i = 0; i < N; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int score, remain;
			scanf("%d%d", &score, &remain);

			stk.push(current);
			current = { score, remain };
		}

		if (current.score == -1 && current.remain == -1) {
			continue;
		}

		--current.remain;

		if (current.remain == 0) {
			result += current.score;
			current = stk.top();
			stk.pop();
		}
	}

	printf("%d\n", result);

	return 0;
}