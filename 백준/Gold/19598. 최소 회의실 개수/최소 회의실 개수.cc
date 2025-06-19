#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> v(N);
	for (pair<int, int>& p : v) {
		scanf("%d%d", &p.first, &p.second);
	}

	sort(v.begin(), v.end());

	int result = 0;
	int cur = 0;
	priority_queue<int, vector<int>, greater<int>> end_time;
	for (const pair<int, int>& p : v) {
		while ((end_time.empty() == false) && (end_time.top() <= p.first)) {
			end_time.pop();
			--cur;
		}

		end_time.push(p.second);
		++cur;
		result = max(result, cur);
	}

	printf("%d\n", result);

	return 0;
}