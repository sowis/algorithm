#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef struct _edge {
	int y;
	int x;
	bool begin;

	bool operator<(const _edge& e) const {
		return this->x > e.x;
	}
} Edge;

int main(void) {
	int N;
	scanf("%d", &N);

	priority_queue<Edge> q;

	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);

		q.push({ y, x, true });
		q.push({ y, x + 10, false });
	}

	vector<int> board(100, 0);
	int colored_length = 0;
	int current_x = 0;
	int result = 0;

	while (q.empty() == false) {
		const Edge e = q.top();
		q.pop();

		result += (e.x - current_x) * colored_length;
		current_x = e.x;

		if (e.begin) {
			for (int y = e.y; y < e.y + 10; ++y) {
				++board[y];

				if (board[y] == 1) {
					++colored_length;
				}
			}
		}
		else {
			for (int y = e.y; y < e.y + 10; ++y) {
				--board[y];

				if (board[y] == 0) {
					--colored_length;
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}