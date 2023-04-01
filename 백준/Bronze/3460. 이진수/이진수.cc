#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> to_bin(int N) {
	vector<int> result;

	while (N > 0) {
		result.push_back(N % 2);
		N /= 2;
	}

	return result;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		const vector<int> bin = to_bin(N);
		for (int i = 0; i < bin.size(); ++i) {
			if (bin[i] == 1) {
				printf("%d ", i);
			}
		}

		printf("\n");
	}

	return 0;
}