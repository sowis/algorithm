#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct data {
	int value;
	int id;

	bool operator< (const struct data& d) const {
		return this->value < d.value;
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<struct data> v(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &v[i].value);
		v[i].id = i;
	}

	stable_sort(v.begin(), v.end());

	int result = 0;
	for (int i = 0; i < N; ++i) {
		result = max(result, v[i].id - i);
	}

	printf("%d\n", result + 1);

	return 0;
}