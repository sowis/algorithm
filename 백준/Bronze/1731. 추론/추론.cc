#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int& num : v) {
		scanf("%d", &num);
	}

	if (v[2] - v[1] == v[1] - v[0]) {
		printf("%d\n", v[v.size() - 1] + v[1] - v[0]);
	}
	else {
		printf("%d\n", v[v.size() - 1] * (v[1] / v[0]));
	}

	return 0;
}