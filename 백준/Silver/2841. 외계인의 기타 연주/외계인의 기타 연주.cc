#include <cstdio>
#include <stack>

using namespace std;

stack<int> guitar[300001];

int main(void) {
	int N, P;
	scanf("%d%d", &N, &P);

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int str, fret;
		scanf("%d%d", &str, &fret);

		while (guitar[str].empty() == false && fret < guitar[str].top()) {
			guitar[str].pop();
			++result;
		}

		if (guitar[str].empty() || guitar[str].top() != fret) {
			guitar[str].push(fret);
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}