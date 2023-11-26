#include <cstdio>
#include <vector>

using namespace std;

vector<int> next(const vector<int>& current) {
	vector<int> result;
	for (int i = 0; i < current.size(); ++i) {
		if (i % 2 == 0) {
			continue;
		}

		result.push_back(current[i]);
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		v[i] = i + 1;
	}

	while (v.size() > 1) {
		v = next(v);
	}

	printf("%d\n", v[0]);

	return 0;
}