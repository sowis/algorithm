#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> A(N), B(M);
	for (int& a : A) {
		scanf("%d", &a);
	}

	for (int& b : B) {
		scanf("%d", &b);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int result = 0;
	for (const int a : A) {
		result += lower_bound(B.begin(), B.end(), a) - B.begin();
	}

	printf("%d\n", result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}