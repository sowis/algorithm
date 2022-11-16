#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> lis;
	for (int i = 0; i < N; ++i) {
		int number;
		scanf("%d", &number);

		const vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), number);
		if (it == lis.end()) {
			lis.push_back(number);
		}
		else {
			*it = number;
		}
	}

	printf("%d\n", N - (int)lis.size());

	return 0;
}