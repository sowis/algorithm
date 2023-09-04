#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> v(3);

	for (int i = 0; i < 3; ++i) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v[1] + v[2]);

	return 0;
}