#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

int result = 0;

void solve(const list<int>& l, const int energy = 0) {
	if (l.size() <= 2) {
		result = max(result, energy);
		return;
	}

	for (int target = 1; target < l.size() - 1; ++target) {
		list<int> copy = l;
		auto it = copy.begin();
		for (int i = 0; i < target - 1; ++i) {
			++it;
		}

		int add_energy = *it;
		++it;
		++it;
		add_energy *= *it;
		--it;
		copy.erase(it);
		solve(copy, energy + add_energy);
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	list<int> list;
	for (int i = 0; i < N; ++i) {
		int weight;
		scanf("%d", &weight);

		list.push_back(weight);
	}

	solve(list);

	printf("%d\n", result);

	return 0;
}