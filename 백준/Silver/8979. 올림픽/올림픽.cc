#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int gold;
	int silver;
	int bronze;

	bool operator== (const struct _data& d) const {
		return (gold == d.gold) && (silver == d.silver) && (bronze == d.bronze);
	}

	bool operator< (const struct _data& d) const {
		if (gold != d.gold) {
			return gold > d.gold;
		}

		if (silver != d.silver) {
			return silver > d.silver;
		}

		return bronze > d.bronze;
	}
} Data;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	Data target;
	vector<Data> v(N);
	for (int i = 0; i < N; ++i) {
		int id;
		scanf("%d", &id);
		scanf("%d%d%d", &v[i].gold, &v[i].silver, &v[i].bronze);

		if (id == K) {
			target = v[i];
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) {
		if (v[i] == target) {
			printf("%d\n", i + 1);
			return 0;
		}
	}

	return 0;
}