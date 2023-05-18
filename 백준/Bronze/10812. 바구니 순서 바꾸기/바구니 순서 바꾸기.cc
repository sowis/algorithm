#include <cstdio>
#include <vector>

using namespace std;

void spin(vector<int>& v, const int begin, const int mid, const int end) {
	vector<int> tmp(end - begin + 1);
	int idx = 0;

	for (int i = mid; i <= end; ++i) {
		tmp[idx] = v[i];
		++idx;
	}

	for (int i = begin; i < mid; ++i) {
		tmp[idx] = v[i];
		++idx;
	}

	for (int i = begin; i <= end; ++i) {
		v[i] = tmp[i - begin];
	}
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> v(N + 1);
	for (int i = 0; i <= N; ++i) {
		v[i] = i;
	}

	for (int a = 0; a < M; ++a) {
		int begin, mid, end;
		scanf("%d%d%d", &begin, &end, &mid);
		spin(v, begin, mid, end);
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", v[i]);
	}

	return 0;
}