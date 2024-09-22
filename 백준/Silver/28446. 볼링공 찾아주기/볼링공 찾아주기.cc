#include <cstdio>
#include <unordered_map>

using namespace std;

int main(void) {
	int M;
	scanf("%d", &M);

	unordered_map<int, int> board;
	for (int i = 0; i < M; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int x, w;
			scanf("%d%d", &x, &w);

			board[w] = x;
		}
		else {
			int w;
			scanf("%d", &w);

			printf("%d\n", board[w]);
		}
	}

	return 0;
}