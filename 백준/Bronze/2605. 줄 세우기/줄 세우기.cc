#include <cstdio>
#include <list>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	list<int> result;
	for (int i = 1; i <= N; ++i) {
		int pick;
		scanf("%d", &pick);

		list<int>::iterator it = result.end();
		for (int k = 0; k < pick; ++k) {
			--it;
		}

		result.insert(it, i);
	}

	for (const int r : result) {
		printf("%d ", r);
	}

	return 0;
}