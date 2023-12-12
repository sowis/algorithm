#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int nation;
	int id;
	int score;

	bool operator<(const struct _data& d) const {
		return score > d.score;
	}
} Data;

int main(void) {
	int N;
	scanf("%d\n", &N);

	vector<Data> v(N);
	for (Data& d : v) {
		scanf("%d%d%d", &d.nation, &d.id, &d.score);
	}

	sort(v.begin(), v.end());

	vector<int> n_count(1001, 0);
	int winner_count = 0;
	for (const Data& d : v) {
		if (n_count[d.nation] == 2) {
			continue;
		}

		printf("%d %d\n", d.nation, d.id);
		++n_count[d.nation];
		++winner_count;

		if (winner_count == 3) {
			break;
		}
	}

	return 0;
}