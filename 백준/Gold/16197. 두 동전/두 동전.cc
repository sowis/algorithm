#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

enum {
	IN = 0,
	OUT = 1
};

typedef struct _data {
	pair<int, int> p1;
	pair<int, int> p2;
	int move_count;
} Data;

int main(void) {
	int N, M;
	cin >> N >> M;

	bool find = false;
	pair<int, int> pos1, pos2;
	vector<vector<char>> board(N, vector<char>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'o') {
				if (find) {
					pos2 = { y, x };
				}
				else {
					pos1 = { y, x };
				}

				find = true;
			}
		}
	}
	
	queue<Data> q;
	q.push({ pos1, pos2, 0 });
	
	while (q.empty() == false) {
		const Data data = q.front();
		q.pop();

		if (data.move_count >= 10) {
			break;
		}

		for (int i = 0; i < 4; ++i) {

			pair<int, int> next_1 = { data.p1.first + directions[i][0], data.p1.second + directions[i][1] };
			pair<int, int> next_2 = { data.p2.first + directions[i][0], data.p2.second + directions[i][1] };

			const int next_1_io = (next_1.first < 0 || N <= next_1.first || next_1.second < 0 || M <= next_1.second);
			const int next_2_io = (next_2.first < 0 || N <= next_2.first || next_2.second < 0 || M <= next_2.second);

			if (next_1_io == OUT && next_2_io == OUT) {
				continue;
			}

			if (next_1_io != next_2_io) {
				cout << data.move_count + 1 << "\n";
				return 0;
			}

			if (board[next_1.first][next_1.second] == '#') {
				next_1 = data.p1;
			}

			if (board[next_2.first][next_2.second] == '#') {
				next_2 = data.p2;
			}

			if (next_1 == next_2) {
				continue;
			}

			if (next_1 == data.p1 && next_2 == data.p2) {
				continue;
			}

			q.push({ next_1, next_2, data.move_count + 1 });
		}
	}

	cout << -1 << "\n";

	return 0;
}