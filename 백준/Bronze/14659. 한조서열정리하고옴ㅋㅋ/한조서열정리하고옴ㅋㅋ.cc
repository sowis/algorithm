#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> hanzo(N);
	for (int& height : hanzo) {
		scanf("%d", &height);
	}

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int kill = 0;
		for (int k = i + 1; k < N; ++k) {
			if (hanzo[k] < hanzo[i]) {
				++kill;
			}
			else if (hanzo[k] > hanzo[i]) {
				break;
			}
		}

		result = max(result, kill);
	}

	printf("%d\n", result);

	return 0;
}