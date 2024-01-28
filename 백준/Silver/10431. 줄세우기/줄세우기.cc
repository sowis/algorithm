#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int case_num;
	scanf("%d", &case_num);

	vector<int> childrens(20);
	for (int& c : childrens) {
		scanf("%d", &c);
	}

	int result = 0;
	vector<int> v(20);
	v[0] = childrens[0];

	for (int i = 1; i < 20; ++i) {
		int bigger = -1;
		for (int k = 0; k < i; ++k) {
			if (childrens[i] < v[k]) {
				bigger = k;
				break;
			}
		}

		if (bigger == -1) {
			v[i] = childrens[i];
		}
		else {
			result += i - bigger;

			for (int k = i; k > bigger; --k) {
				v[k] = v[k - 1];
			}

			v[bigger] = childrens[i];
		}
	}

	printf("%d %d\n", case_num, result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}