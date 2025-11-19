#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int directions[2][2] = { {-1, 0}, {0, -1} };

long long N, M;
vector<vector<long long>> board;
unordered_set<int> broken;

inline int edge_serialize(const int a, const int b, const int c, const int d) {
	return (a << 24) | (b << 16) | (c << 8) | d;
}

bool is_edge_exist(const int a, const int b, const int c, const int d) {
	const int serialized = edge_serialize(a, b, c, d);
	return broken.find(serialized) != broken.end();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	board = vector<vector<long long>>(N + 1, vector<long long>(M + 1, 0));

	int K;
	cin >> K;
	
	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		broken.insert(edge_serialize(a, b, c, d));
		broken.insert(edge_serialize(c, d, a, b));
	}

	board[0][0] = 1;
	
	for (int y = 0; y <= N; ++y) {
		for (int x = 0; x <= M; ++x) {
			for (int i = 0; i < 2; ++i) {
				const int last_y = y + directions[i][0];
				const int last_x = x + directions[i][1];

				if (last_y < 0 || last_x < 0) {
					continue;
				}

				if (is_edge_exist(y, x, last_y, last_x)) {
					continue;
				}

				board[y][x] += board[last_y][last_x];
			}
		}
	}

	cout << board[N][M];

	return 0;
}