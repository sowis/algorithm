#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
constexpr int WHITE = 0;
constexpr int RED = 1;
constexpr int BLUE = 2;

typedef struct {
	int id;
	int y;
	int x;
	int direction;
} Mal;

int N, K;
int board_colors[12][12];
vector<Mal> board[12][12];
vector<Mal> mals;

int opposite_direction(const int direction) {
	if (direction == 0) {
		return 1;
	}
	else if (direction == 1) {
		return 0;
	}
	else if (direction == 2) {
		return 3;
	}
	else {
		return 2;
	}
}

// 이동 후 게임 끝남: true / 안끝남: false
bool mal_move(Mal& mal) {
	int next_y = mal.y + directions[mal.direction][0];
	int next_x = mal.x + directions[mal.direction][1];

	deque<Mal> mover;

	if ((next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) || (board_colors[next_y][next_x] == BLUE)) {
		mal.direction = opposite_direction(mal.direction);
		next_y = mal.y + directions[mal.direction][0];
		next_x = mal.x + directions[mal.direction][1];

		if ((next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) || (board_colors[next_y][next_x] == BLUE)) {
			return false;
		}
		else if (board_colors[next_y][next_x] == WHITE) {
			for (int i = (int)board[mal.y][mal.x].size() - 1; i >= 0; --i) { // 옮길 말 따로 빼기
				Mal target_mal = board[mal.y][mal.x][i];
				board[mal.y][mal.x].pop_back();

				target_mal.y = next_y;
				target_mal.x = next_x;
				mover.push_front(target_mal);

				if (target_mal.id == mal.id) {
					break;
				}
			}
		}
		else {
			for (int i = (int)board[mal.y][mal.x].size() - 1; i >= 0; --i) { // 옮길 말 따로 빼기
				Mal target_mal = board[mal.y][mal.x][i];
				board[mal.y][mal.x].pop_back();

				target_mal.y = next_y;
				target_mal.x = next_x;
				mover.push_back(target_mal);

				if (target_mal.id == mal.id) {
					break;
				}
			}
		}
	}
	else if (board_colors[next_y][next_x] == WHITE) {
		for (int i = (int)board[mal.y][mal.x].size() - 1; i >= 0; --i) { // 옮길 말 따로 빼기
			Mal target_mal = board[mal.y][mal.x][i];
			board[mal.y][mal.x].pop_back();

			target_mal.y = next_y;
			target_mal.x = next_x;
			mover.push_front(target_mal);

			if (target_mal.id == mal.id) {
				break;
			}
		}
	}
	else {
		for (int i = (int)board[mal.y][mal.x].size() - 1; i >= 0; --i) { // 옮길 말 따로 빼기
			Mal target_mal = board[mal.y][mal.x][i];
			board[mal.y][mal.x].pop_back();

			target_mal.y = next_y;
			target_mal.x = next_x;
			mover.push_back(target_mal);

			if (target_mal.id == mal.id) {
				break;
			}
		}
	}

	for (const Mal& target_mal : mover) { // 말 옮기기
		board[next_y][next_x].push_back(target_mal);

		mals[target_mal.id].y = next_y;
		mals[target_mal.id].x = next_x;
	}

	if (board[next_y][next_x].size() >= 4) { // 4개이상 쌓여있는지 검사
		return true;
	}

	return false;
}

int main(void) {
	scanf("%d%d", &N, &K);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board_colors[y][x]);
		}
	}

	for (int i = 0; i < K; ++i) {
		Mal mal;
		mal.id = i;
		scanf("%d%d%d", &mal.y, &mal.x, &mal.direction);

		/* 0부터 시작하기 위해 */
		--mal.y;
		--mal.x;
		--mal.direction;
		/**********************/

		mals.push_back(mal);
		board[mal.y][mal.x].push_back(mal);
	}

	for (int i = 1; i < 1001; ++i) {
		for (int k = 0; k < K; ++k) {
			if (mal_move(mals[k])) {
				printf("%d\n", i);
				return 0;
			}
		}
	}

	printf("-1\n");

	return 0;
}