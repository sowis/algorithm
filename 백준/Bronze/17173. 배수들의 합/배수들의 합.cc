#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> v(M);
	for (int& num : v) {
		scanf("%d", &num);
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		bool ok = false;
		for (const int n : v) {
			if (i % n == 0) {
				ok = true;
				break;
			}
		}

		if (ok) {
			result += i;
		}
	}

	printf("%d\n", result);

	return 0;
}