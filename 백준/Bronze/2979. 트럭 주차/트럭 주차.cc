#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);

	vector<int> times(101, 0);
	for (int i = 0; i < 3; ++i) {
		int begin, end;
		scanf("%d%d", &begin, &end);

		for (int k = begin; k < end; ++k) {
			++times[k];
		}
	}

	int result = 0;
	for (int i = 0; i < 101; ++i) {
		if (times[i] == 1) {
			result += A;
		}
		else if (times[i] == 2) {
			result += B * 2;
		}
		else if (times[i] == 3) {
			result += C * 3;
		}
	}

	printf("%d\n", result);

	return 0;
}