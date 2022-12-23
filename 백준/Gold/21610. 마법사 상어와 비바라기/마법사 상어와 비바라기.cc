#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int directions[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
constexpr int diagonals[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

int N, M;
vector<vector<int>> board;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const& pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

inline pair<int, int> move(const pair<int, int>& cloud, const int direction, const int hop) {
	return pair<int, int>{ (cloud.first + (directions[direction][0] + N) * hop) % N, (cloud.second + (directions[direction][1] + N) * hop) % N };
}

unordered_set<pair<int, int>, pair_hash> next(const int d, const int s, const unordered_set<pair<int, int>, pair_hash>& clouds) {
	unordered_set<pair<int, int>, pair_hash> moved_clouds;
	for (const pair<int, int>& cloud : clouds) {
		const pair<int, int> moved_cloud = move(cloud, d, s);
		++board[moved_cloud.first][moved_cloud.second];
		moved_clouds.insert(moved_cloud);
	}

	for (const pair<int, int>& moved_cloud : moved_clouds) {
		int water_basket_count = 0;
		for (int i = 0; i < 4; ++i) {
			const int dia_y = moved_cloud.first + diagonals[i][0];
			const int dia_x = moved_cloud.second + diagonals[i][1];

			if (dia_y < 0 || dia_y >= N || dia_x < 0 || dia_x >= N) {
				continue;
			}

			if (board[dia_y][dia_x] > 0) {
				++water_basket_count;
			}
		}

		board[moved_cloud.first][moved_cloud.second] += water_basket_count;
	}

	unordered_set<pair<int, int>, pair_hash> next_clouds;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] < 2) {
				continue;
			}

			if (moved_clouds.find({ y, x }) != moved_clouds.end()) {
				continue;
			}

			next_clouds.insert({ y, x });
			board[y][x] -= 2;
		}
	}

	return next_clouds;
}

int main(void) {
	scanf("%d%d", &N, &M);

	board = vector<vector<int>>(N, vector<int>(N));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	unordered_set<pair<int, int>, pair_hash> clouds;
	clouds.insert({ N - 1, 0 });
	clouds.insert({ N - 1, 1 });
	clouds.insert({ N - 2, 0 });
	clouds.insert({ N - 2, 1 });

	for (int i = 0; i < M; ++i) {
		int d, s;
		scanf("%d%d", &d, &s);

		--d;
		clouds = next(d, s, clouds);
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			result += board[y][x];
		}
	}

	printf("%d\n", result);

	return 0;
}