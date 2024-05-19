#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> v(N);
	for (pair<int, int>& p : v) {
		scanf("%d%d", &p.first, &p.second);
	}

	sort(v.begin(), v.end());

	vector<pair<int, int>> results;
	for (const pair<int, int>& p : v) {
		bool ok = true;
		for (const pair<int, int>& r : results) {
			if (r.first <= p.first && r.second <= p.second) {
				ok = false;
				break;
			}
		}

		if (ok == false) {
			continue;
		}

		results.push_back(p);
	}

	printf("%zd\n", results.size());

	return 0;
}