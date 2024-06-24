#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<bool> visit(N + 1, false);
	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		if (visit[input]) {
			printf("%d\n", input);
			break;
		}

		visit[input] = true;
	}

	return 0;
}