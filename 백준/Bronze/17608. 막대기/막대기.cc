#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int& number : v) {
		scanf("%d", &number);
	}

	int max_height = -1;
	int result = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (v[i] > max_height) {
			++result;
			max_height = v[i];
		}
	}

	printf("%d\n", result);

	return 0;
}