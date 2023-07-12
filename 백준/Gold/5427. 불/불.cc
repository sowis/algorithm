#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
constexpr int infinite = numeric_limits<int>::max();

enum BOARD_ITEM {
	EMPTY = '.',
	WALL = '#',
	PLAYER = '@',
	FIRE = '*'
};

typedef struct {
	int y;
	int x;
	int time;
} TimePoint;

typedef vector<vector<char>> Board;
typedef vector<vector<int>> BoardTimer;

void test_case(void) {
	int w, h;
	cin >> w >> h;

	Board board = vector<vector<char>>(h, vector<char>(w));
	queue<TimePoint> players;
	queue<TimePoint> fires;
	BoardTimer player_time(h, vector<int>(w, infinite));
	BoardTimer fire_time(h, vector<int>(w, infinite));
	vector<pair<int, int>> exits;

	/* 지도 입력받기 */
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> board[y][x];

			if (board[y][x] == BOARD_ITEM::PLAYER) {
				players.push({ y, x, 0 });
				player_time[y][x] = 0;
			}

			if (board[y][x] == BOARD_ITEM::FIRE) {
				fires.push({ y, x, 0 });
				fire_time[y][x] = 0;
			}

			if (board[y][x] == BOARD_ITEM::PLAYER || board[y][x] == BOARD_ITEM::EMPTY) {
				if (y == 0 || y == h - 1 || x == 0 || x == w - 1) {
					exits.push_back({ y, x });
				}
			}
		}
	}
	/***************/

	/* 각 타일에 불이 언제 번지는지 계산 */
	while (fires.empty() == false) {
		const TimePoint fire = fires.front();
		fires.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = fire.y + directions[i][0];
			const int next_x = fire.x + directions[i][1];

			if (next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) {
				continue;
			}

			if (board[next_y][next_x] == BOARD_ITEM::WALL) {
				continue;
			}

			if (fire_time[next_y][next_x] <= fire.time + 1) {
				continue;
			}

			fire_time[next_y][next_x] = fire.time + 1;
			fires.push({ next_y, next_x, fire.time + 1 });
		}
	}
	/****************************************/

	/* 각 타일까지 이동하는 데 얼마자 걸리는지 계산 */
	while (players.empty() == false) {
		const TimePoint player = players.front();
		players.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = player.y + directions[i][0];
			const int next_x = player.x + directions[i][1];

			if (next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) {
				continue;
			}

			if (board[next_y][next_x] == BOARD_ITEM::WALL || fire_time[next_y][next_x] <= player.time + 1) {
				continue;
			}

			if (player_time[next_y][next_x] <= player.time + 1) {
				continue;
			}

			player_time[next_y][next_x] = player.time + 1;
			players.push({ next_y, next_x, player.time + 1 });
		}
	}
	/*************************************************/

	int result = infinite;
	for (const pair<int, int>& exit : exits) {
		result = min(result, player_time[exit.first][exit.second]);
	}

	if (result == infinite) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << result + 1 << "\n";
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}