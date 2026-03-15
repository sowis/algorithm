#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int directions[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
constexpr int EMPTY = 1987654321;

typedef struct _data {
	int y;
	int x;
	int dist;
	int remain_moves;
} Data;

typedef struct _mal {
	int y;
	int x;
	int id;
} Mal;

int N, M;
vector<Mal> mal_begins;
vector<vector<vector<int>>> min_distances;

vector<vector<int>> move_counts(const Mal &mal) {
	vector<vector<int>> results(N, vector<int>(M, EMPTY));

	queue<Data> q;
	q.push({ mal.y, mal.x, 0, 0});
	results[mal.y][mal.x] = 0;

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (results[next_y][next_x] != EMPTY) {
				continue;
			}

			if (d.remain_moves == 0) {
				q.push({ next_y, next_x, d.dist + 1, mal.id - 1 });
				results[next_y][next_x] = d.dist + 1;
			}
			else {
				q.push({ next_y, next_x, d.dist, d.remain_moves - 1 });
				results[next_y][next_x] = d.dist;
			}
		}
	}

	return results;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char c;
			cin >> c;

			if (c == '.') {
				continue;
			}

			mal_begins.push_back({ y, x , c - '0'});
		}
	}

	for (const Mal& mal_begin : mal_begins) {
		min_distances.push_back(move_counts(mal_begin));
	}

	int result = EMPTY;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int dist_sum = 0;

			for (const vector<vector<int>>& dists : min_distances) {
				if (dists[y][x] == EMPTY) {
					dist_sum = EMPTY;
					break;
				}

				dist_sum += dists[y][x];
			}

			result = min(result, dist_sum);
		}
	}

	if (result == EMPTY) {
		result = -1;
	}

	cout << result;

	return 0;
}