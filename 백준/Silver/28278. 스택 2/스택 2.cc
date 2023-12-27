#include <cstdio>
#include <stack>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	stack<int> stk;
	for (int i = 0; i < N; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int n;
			scanf("%d", &n);

			stk.push(n);
		}
		else if (op == 2) {
			if (stk.empty()) {
				printf("-1\n");
			}
			else {
				const int t = stk.top();
				stk.pop();
				printf("%d\n", t);
			}
		}
		else if (op == 3) {
			printf("%zd\n", stk.size());
		}
		else if (op == 4) {
			printf("%d\n", stk.empty() ? 1 : 0);
		}
		else {
			if (stk.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stk.top());
			}
		}
	}

	return 0;
}