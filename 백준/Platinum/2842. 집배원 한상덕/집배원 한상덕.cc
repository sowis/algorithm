#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int N;
vector<vector<char>> board;
vector<vector<int>> heights;
vector<int> v_heights;
vector<pair<int, int>> targets;

void dfs(const int min_height, const int max_height, vector<vector<bool>>& visit, const int y, const int x) {
	visit[y][x] = true;
	for (int i = 0; i < 8; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
			continue;
		}

		const int next_height = heights[next_y][next_x];
		if (next_height < min_height || max_height < next_height) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		dfs(min_height, max_height, visit, next_y, next_x);
	}
}

bool ok(const int min_height, const int max_height) {
	const int begin_height = heights[targets[0].first][targets[0].second];
	if (begin_height < min_height || max_height < begin_height) {
		return false;
	}

	vector<vector<bool>> visit(N, vector<bool>(N, false));
	dfs(min_height, max_height, visit, targets[0].first, targets[0].second);

	for (const pair<int, int>& target : targets) {
		if (visit[target.first][target.second] == false) {
			return false;
		}
	}

	return true;
}

int main(void) {
	cin >> N;
	
	board = vector<vector<char>>(N, vector<char>(N));
	heights = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'P' || board[y][x] == 'K') {
				targets.push_back({ y, x });
			}
		}
	}

	unordered_set<int> heights_dup_delete;
	int max_height = numeric_limits<int>::min();
	int min_height = numeric_limits<int>::max();

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> heights[y][x];

			if (board[y][x] == 'P' || board[y][x] == 'K') {
				max_height = max(max_height, heights[y][x]);
				min_height = min(min_height, heights[y][x]);
			}

			heights_dup_delete.insert(heights[y][x]);
		}
	}

	for (const int height : heights_dup_delete) {
		v_heights.push_back(height);
	}

	sort(v_heights.begin(), v_heights.end());

	int max_height_index = 0;
	int min_height_index = 0;

	for (int i = 0; i < v_heights.size(); ++i) {
		if (max_height == v_heights[i]) {
			max_height_index = i;
		}
	}

	int result = numeric_limits<int>::max();
	while (max_height_index < v_heights.size()) {
		while (true) {
			if (ok(v_heights[min_height_index], v_heights[max_height_index])) {
				result = min(result, v_heights[max_height_index] - v_heights[min_height_index]);
				++min_height_index;
			}
			else {
				break;
			}
		}

		++max_height_index;
	}

	cout << result << "\n";

	return 0;
}