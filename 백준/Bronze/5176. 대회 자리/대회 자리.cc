#include <cstdio>
#include <vector>

using namespace std;

void test_case(void) {
	int P, M;
	scanf("%d%d", &P, &M);

	vector<bool> visit(M + 1, false);
	int result = 0;

	for (int i = 0; i < P; ++i) {
		int want;
		scanf("%d", &want);

		if (visit[want]) {
			++result;
		}
		
		visit[want] = true;
	}

	printf("%d\n", result);
}

int main(void) {
	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; ++i) {
		test_case();
	}

	return 0;
}