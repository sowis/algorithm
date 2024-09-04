#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int & num: v) {
		scanf("%d", &num);
	}

	sort(v.begin(), v.end());

	for (int i = 10000; i >= 0; --i) {
		const int more = (v.end() - lower_bound(v.begin(), v.end(), i));
		if (i <= more) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}