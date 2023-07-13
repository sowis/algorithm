#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Board;

int N, M, R;

Board op1(const Board& board) {
	Board result = board;
	for (int y = 0; y < N; ++y) {
		const int target_y = N - y - 1;
		result[target_y] = board[y];
	}

	return result;
}

Board op2(const Board& board) {
	Board result = board;
	for (int x = 0; x < M; ++x) {
		const int target_x = M - x - 1;
		for (int y = 0; y < N; ++y) {
			result[y][target_x] = board[y][x];
		}
	}

	return result;
}

Board op3(const Board& board) {
	Board result(M, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			const int target_y = x;
			const int target_x = N - y - 1;
			result[target_y][target_x] = board[y][x];
		}
	}

	swap(N, M);
	return result;
}

Board op4(const Board& board) {
	Board result(M, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			const int target_y = M - x - 1;
			const int target_x = y;
			result[target_y][target_x] = board[y][x];
		}
	}

	swap(N, M);
	return result;
}

void block_move(Board& target, const Board& source, const int source_begin_y, const int source_begin_x, 
	const int target_begin_y, const int target_begin_x, const int y_sz, const int x_sz) {
	for (int offset_y = 0; offset_y < y_sz; ++offset_y) {
		for (int offset_x = 0; offset_x < x_sz; ++offset_x) {
			target[target_begin_y + offset_y][target_begin_x + offset_x] = source[source_begin_y + offset_y][source_begin_x + offset_x];
		}
	}
}

Board op5(const Board& board) {
	Board result = board;
	const int block_size_y = N / 2;
	const int block_size_x = M / 2;
	const int half_y = (N % 2) ? N / 2 + 1 : N / 2;
	const int half_x = (M % 2) ? M / 2 + 1 : M / 2;

	block_move(result, board, 0, 0, 0, half_x, block_size_y, block_size_x);
	block_move(result, board, 0, half_x, half_y, half_x, block_size_y, block_size_x);
	block_move(result, board, half_y, half_x, half_y, 0, block_size_y, block_size_x);
	block_move(result, board, half_y, 0, 0, 0, block_size_y, block_size_x);
	return result;
}

Board op6(const Board& board) {
	Board result = board;
	const int block_size_y = N / 2;
	const int block_size_x = M / 2;
	const int half_y = (N % 2) ? N / 2 + 1 : N / 2;
	const int half_x = (M % 2) ? M / 2 + 1 : M / 2;

	block_move(result, board, 0, 0, half_y, 0, block_size_y, block_size_x);
	block_move(result, board, half_y, 0, half_y, half_x, block_size_y, block_size_x);
	block_move(result, board, half_y, half_x, 0, half_x, block_size_y, block_size_x);
	block_move(result, board, 0, half_x, 0, 0, block_size_y, block_size_x);
	return result;
}

Board op(const Board& board, const int operation_number) {
	const static vector<Board (*)(const Board&)> functions{op1, op2, op3, op4, op5, op6};
	return functions[operation_number - 1](board);
}

int main(void) {
	scanf("%d%d%d", &N, &M, &R);

	Board board(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	vector<int> operations(R);
	for (int& op : operations) {
		scanf("%d", &op);
	}

	for (const int operation : operations) {
		const Board next = op(board, operation);
		board = next;
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			printf("%d ", board[y][x]);
		}

		printf("\n");
	}

	return 0;
}