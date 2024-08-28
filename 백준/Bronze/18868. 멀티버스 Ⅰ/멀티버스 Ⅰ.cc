#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool v_same(const vector<int>& v1, const vector<int>& v2) {
	for (int i = 0; i < v1.size() - 1; ++i) {
		for (int k = i + 1; k < v1.size(); ++k) {
			if (v1[i] < v1[k]) {
				if (v2[i] >= v2[k]) {
					return false;
				}
			}
			else if (v1[i] == v1[k]) {
				if (v2[i] != v2[k]) {
					return false;
				}
			}
			else {
				if (v2[i] <= v2[k]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main(void) {
	int M, N;
	scanf("%d%d", &M, &N);

	vector<vector<int>> vectors(M);
	for (int i = 0; i < M; ++i) {
		vectors[i] = vector<int>(N);
		for (int& num : vectors[i]) {
			scanf("%d", &num);
		}
	}

	int result = 0;
	for (int i = 0; i < M - 1; ++i) {
		for (int k = i + 1; k < M; ++k) {
			if (v_same(vectors[i], vectors[k])) {
				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}