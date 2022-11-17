#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> edges;
vector<bool> v;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);


	v = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (const int first_friend : edges[1]) {
		v[first_friend] = true;

		for (const int second_friend : edges[first_friend]) {
			v[second_friend] = true;
		}
	}

	int result = 0;
	for (int i = 2; i <= N; ++i) {
		if (v[i]) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}