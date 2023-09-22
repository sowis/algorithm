#include <cstdio>
#include <vector>

using namespace std;

void test_case(void) {
	vector<int> v(3);
	for (int& num : v) {
		scanf("%d", &num);
	}

	if (v[0] > v[1] && v[1] > v[2]) {
		printf("Ordered\n");
	}
	else if (v[0] < v[1] && v[1] < v[2]) {
		printf("Ordered\n");
	}
	else {
		printf("Unordered\n");
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	printf("Gnomes:\n");

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}