#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> eggs;
int result = 0;

void egg_break(const int idx = 0) {
	if (idx == N) {
		int break_count = 0;
		for (const pair<int, int>& egg : eggs) {
			if (egg.first <= 0) {
				++break_count;
			}
		}

		result = max(result, break_count);
		return;
	}

	if (eggs[idx].first <= 0) {
		egg_break(idx + 1);
		return;
	}

	const pair<int, int> backup_me = eggs[idx];
	bool hit = false;

	for (int target_idx = 0; target_idx < N; ++target_idx) {
		if (target_idx == idx) {
			continue;
		}

		if (eggs[target_idx].first <= 0) {
			continue;
		}

		const pair<int, int> backup_target = eggs[target_idx];
		eggs[target_idx].first -= eggs[idx].second;
		eggs[idx].first -= eggs[target_idx].second;
		egg_break(idx + 1);
		eggs[target_idx] = backup_target;
		eggs[idx] = backup_me;
		hit = true;
	}

	if (hit == false) {
		egg_break(idx + 1);
	}
}

int main(void) {
	scanf("%d", &N);

	eggs = vector<pair<int, int>>(N);
	for (pair<int, int>& p : eggs) {
		scanf("%d%d", &p.first, &p.second);
	}

	egg_break();

	printf("%d\n", result);

	return 0;
}