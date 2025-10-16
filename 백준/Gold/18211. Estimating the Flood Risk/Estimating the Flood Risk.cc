#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

typedef struct {
	int y;
	int x;
	int min_height;
	int max_height;
} Data;

int W, D, N;
vector<vector<int>> min_heights(51, vector<int>(51, -987654321));
vector<vector<int>> max_heights(51, vector<int>(51, 987654321));

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	cin >> W >> D >> N;

	queue<Data> q;
	for (int i = 0; i < N; ++i) {
		int x, y, z;
		cin >> x >> y >> z;

		--x;
		--y;

		min_heights[y][x] = z;
		max_heights[y][x] = z;
		q.push({ y, x, z, z });
	}

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y > D || next_x < 0 || next_x > W) {
				continue;
			}

			const int next_min_height = d.min_height - 1;
			const int next_max_height = d.max_height + 1;
			bool change = false;
			if (min_heights[next_y][next_x] < next_min_height) {
				min_heights[next_y][next_x] = next_min_height;
				change = true;
			}

			if (next_max_height < max_heights[next_y][next_x]) {
				max_heights[next_y][next_x] = next_max_height;
				change = true;
			}

			if (change) {
				q.push({ next_y, next_x, next_min_height, next_max_height });
			}
		}
	}

	int result = 0;
	for (int y = 0; y < D; ++y) {
		for (int x = 0; x < W; ++x) {
			if (max_heights[y][x] < min_heights[y][x]) {
				cout << "No";
				return 0;
			}

			result += min_heights[y][x];
		}
	}

	cout << result;

	return 0;
}