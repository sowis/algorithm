#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<vector<int>> v(2, vector<int>(7, 0));
	for (int i = 0; i < N; ++i) {
		int s, y;
		scanf("%d%d", &s, &y);

		++v[s][y];
	}

	int result = 0;
	int count = v[0][1] + v[1][1] + v[0][2] + v[1][2];
	result += count / K + ((count % K) ? 1 : 0);

	count = v[0][3] + v[0][4];
	result += count / K + ((count % K) ? 1 : 0);

	count = v[1][3] + v[1][4];
	result += count / K + ((count % K) ? 1 : 0);

	count = v[0][5] + v[0][6];
	result += count / K + ((count % K) ? 1 : 0);

	count = v[1][5] + v[1][6];
	result += count / K + ((count % K) ? 1 : 0);

	printf("%d\n", result);

	return 0;
}