#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int m;
	scanf("%d", &m);
 
	int cur = m;
	int result = m;
	for (int i = 0; i < N; ++i) {
		int in, out;
		scanf("%d%d", &in, &out);

		cur += in;
		cur -= out;

		if (cur < 0) {
			printf("0\n");
			return 0;
		}

		result = max(result, cur);
	}

	printf("%d\n", result);

	return 0;
}