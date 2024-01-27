#include <cstdio>
#include <vector>

using namespace std;

typedef vector<vector<bool>> Sticker;

int N, M, K;
vector<Sticker> stickers;

Sticker rotate(const Sticker& sticker) {
	Sticker result = vector<vector<bool>>(sticker[0].size(), vector<bool>(sticker.size(), false));
	for (int y = 0; y < sticker.size(); ++y) {
		for (int x = 0; x < sticker[0].size(); ++x) {
			const int target_y = x;
			const int target_x = (int)sticker.size() - y - 1;

			result[target_y][target_x] = sticker[y][x];
		}
	}

	return result;
}

bool can_put(const vector<vector<bool>>& board, const Sticker& sticker, const int begin_y, const int begin_x) {
	for (int offset_y = 0; offset_y < sticker.size(); ++offset_y) {
		for (int offset_x = 0; offset_x < sticker[0].size(); ++offset_x) {
			if (sticker[offset_y][offset_x] == false) {
				continue;
			}

			if (((begin_y + offset_y) >= board.size()) || ((begin_x + offset_x) >= board[0].size())) {
				return false;
			}

			if (board[begin_y + offset_y][begin_x + offset_x] == true) {
				return false;
			}
		}
	}

	return true;
}

void put(vector<vector<bool>>& board, const Sticker& sticker, const int begin_y, const int begin_x) {
	for (int offset_y = 0; offset_y < sticker.size(); ++offset_y) {
		for (int offset_x = 0; offset_x < sticker[0].size(); ++offset_x) {
			if (sticker[offset_y][offset_x] == false) {
				continue;
			}

			board[begin_y + offset_y][begin_x + offset_x] = true;
		}
	}
}

bool search_and_put(vector<vector<bool>>& board, const Sticker& sticker) {
	for (int y = 0; y < board.size(); ++y) {
		for (int x = 0; x < board[0].size(); ++x) {
			if (can_put(board, sticker, y, x) == false) {
				continue;
			}

			put(board, sticker, y, x);
			return true;
		}
	}

	return false;
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);

	stickers = vector<Sticker>(K);
	for (Sticker& s : stickers) {
		int r, c;
		scanf("%d%d", &r, &c);

		s = vector<vector<bool>>(r, vector<bool>(c));
		for (int y = 0; y < r; ++y) {
			for (int x = 0; x < c; ++x) {
				int input;
				scanf("%d", &input);
				s[y][x] = (input == 1);
			}
		}
	}

	vector<vector<bool>> board(N, vector<bool>(M, false));
	for (const Sticker& s : stickers) {
		Sticker sticker_phase = s;
		for (int r = 0; ; ++r) {
			if (r == 4) {
				break;
			}

			if (search_and_put(board, sticker_phase)) {
				break;
			}

			sticker_phase = rotate(sticker_phase);
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x]) {
				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}