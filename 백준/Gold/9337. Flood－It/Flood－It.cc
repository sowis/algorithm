#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

vector<pair<int, int>> same_color_pos(const vector<vector<int>>& board) {
	vector<vector<bool>> visit(board.size(), vector<bool>(board.size(), false));
	visit[0][0] = true;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	vector<pair<int, int>> result;
	result.push_back({ 0, 0 });

	while (q.empty() == false) {
		const pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = pos.first + directions[i][0];
			const int next_x = pos.second + directions[i][1];

			if (next_y < 0 || next_y >= board.size() || next_x < 0 || next_x >= board.size()) {
				continue;
			}

			if (board[next_y][next_x] != board[0][0]) {
				continue;
			}
	
			if (visit[next_y][next_x]) {
				continue;
			}
			
			result.push_back({ next_y, next_x });
			visit[next_y][next_x] = true;
			q.push({ next_y, next_x });
		}
	}

	return result;
}

vector<vector<int>> color_change(const vector<vector<int>>& board, const int target_color) {
	vector<vector<int>> change_board = board;
	const vector<pair<int, int>> links = same_color_pos(board);
	for (const pair< int, int>& pos : links) {
		change_board[pos.first][pos.second] = target_color;
	}
	
	return change_board;
}

void test_case(void) {
	int N;
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			char c;
			cin >> c;
			board[y][x] = c - '0';
		}
	}

	vector<int> color_pick(7, 0);
	vector<vector<int>> current_board = board;
	while (same_color_pos(current_board).size() != N * N) {
		int next_color = 0;
		size_t next_link_size = 0;
		vector<vector<int>> next_board;
		for (int target_color = 1; target_color <= 6; ++target_color) {
			const vector<vector<int>> tmp_board = color_change(current_board, target_color);
			size_t link_size = same_color_pos(tmp_board).size();
			if (link_size > next_link_size) {
				next_link_size = link_size;
				next_board = tmp_board;
				next_color = target_color;
			}
		}

		++color_pick[next_color];
		current_board = next_board;
	}

	int move_sum = 0;
	for (const int move_count : color_pick) {
		move_sum += move_count;
	}

	cout << move_sum << '\n';

	for (int i = 1; i <= 6; ++i) {
		cout << color_pick[i] << " ";
	}

	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}