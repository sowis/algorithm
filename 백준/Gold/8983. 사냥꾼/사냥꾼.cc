#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline int distance(const pair<int, int>& pos, const int x) {
	return abs(pos.second - x) + pos.first;
}

int min_dist(const pair<int, int>& pos, const vector<int>& shooter, const int M) {
	const int idx = (int)(lower_bound(shooter.begin(), shooter.end(), pos.second) - shooter.begin());
	
	if (idx == M) {
		return distance(pos, shooter[M - 1]);
	}
	
	int result = distance(pos, shooter[idx]);
	if (0 < idx) {
		result = min(result, distance(pos, shooter[idx - 1]));
	}

	return result;
}

int main(void) {
	int M, N, L;
	scanf("%d%d%d", &M, &N, &L);

	vector<int> shooter(M);
	for (int& s : shooter) {
		scanf("%d", &s);
	}

	sort(shooter.begin(), shooter.end());

	vector<pair<int, int>> games(N);
	for (pair<int, int>& p : games) {
		scanf("%d%d", &p.second, &p.first);
	}

	int result = 0;
	for (const pair<int, int>& p : games) {
		if (min_dist(p, shooter, M) <= L) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}