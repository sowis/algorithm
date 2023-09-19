#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> v(3);
	for (int& num : v) {
		scanf("%d", &num);
	}

	sort(v.begin(), v.end());

	if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
		printf("1\n");
	}
	else if (v[0] == v[1] && v[1] == v[2]) {
		printf("2\n");
	}
	else {
		printf("0\n");
	}

	return 0;
}