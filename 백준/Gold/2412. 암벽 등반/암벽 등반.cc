#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

int n, T;
unordered_map<int, unordered_map<int, int>> min_dist;
unordered_map<int, unordered_map<int, bool>> visit;
queue<Data> q;

int main(void) {
	cin >> n >> T;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;

		min_dist[y][x] = 1987654321;
	}

	min_dist[0][0] = 0;
	visit[0][0] = true;
	q.push({ 0, 0, 0 });

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int offset_y = -2; offset_y <= 2; ++offset_y) {
			for (int offset_x = -2; offset_x <= 2; ++offset_x) {
				const int next_y = d.y + offset_y;
				const int next_x = d.x + offset_x;

				if (next_y < 0 || next_y > T || next_x < 0 || next_x > 1000000) {
					continue;
				}

				if (visit[next_y][next_x]) {
					continue;
				}

				const int next_dist = min_dist[d.y][d.x] + 1;
				if (min_dist[next_y][next_x] <= next_dist) {
					continue;
				}

				visit[next_y][next_x] = true;
				min_dist[next_y][next_x] = next_dist;
				q.push({ next_y, next_x, next_dist });
			}
		}
	}

	int result = 1987654321;
	for (const pair<int, int>& p : min_dist[T]) {
		if (visit[T][p.first]) {
			result = min(result, p.second);
		}
	}

	if (result == 1987654321) {
		result = -1;
	}

	cout << result;

	return 0;
}