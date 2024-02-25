#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int INF = 987654321;

typedef struct _data {
	int monitor;
	int clipboard;
	int time;

	bool operator<(const struct _data& d) const {
		return this->time > d.time;
	}
} Data;

// [현재 화면 이모티콘수][클립보드 이모티콘 수] = 이 상태가 되기까지의 최소 시간
vector<vector<int>> cache(1001, vector<int>(1001, INF));

int main(void) {
	int S;
	scanf("%d", &S);

	priority_queue<Data> q;
	cache[1][0] = 0;
	q.push({ 1, 0, 0 });

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (cache[d.monitor][d.clipboard] < d.time) {
			continue;
		}

		/* 화면 -> 클립보드 */
		if (d.time + 1 < cache[d.monitor][d.monitor]) {
			cache[d.monitor][d.monitor] = d.time + 1;
			q.push({ d.monitor, d.monitor, d.time + 1 });
		}
		/*******************/

		/* 클립보드 -> 화면 */
		if (d.monitor + d.clipboard <= S && 
			d.time + 1 < cache[d.monitor + d.clipboard][d.clipboard]) {
			cache[d.monitor + d.clipboard][d.clipboard] = d.time + 1;
			q.push({ d.monitor + d.clipboard, d.clipboard, d.time + 1 });
		}
		/*******************/

		/* 화면 이모티콘 1개 삭제 */
		if (0 < d.monitor &&
			d.time + 1 < cache[d.monitor - 1][d.clipboard]) {
			cache[d.monitor - 1][d.clipboard] = d.time + 1;
			q.push({ d.monitor - 1, d.clipboard, d.time + 1 });
		}
		/**************************/
	}

	int result = 987654321;
	for (int clipboard = 0; clipboard < S; ++clipboard) {
		result = min(result, cache[S][clipboard]);
	}

	printf("%d\n", result);

	return 0;
}