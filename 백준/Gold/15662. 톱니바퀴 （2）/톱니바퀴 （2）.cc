#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<int>> gears;
vector<int> gear_top;

int gear_right(const int id) {
	return gears[id][(gear_top[id] + 2) % 8];
}

int gear_left(const int id) {
	return gears[id][(gear_top[id] + 6) % 8];
}

void rotate(const int id, const int direction, const bool to_move_left = true, const bool to_move_right = true) {
	if (to_move_left && 1 < id && gear_right(id - 1) != gear_left(id)) {
		rotate(id - 1, direction * -1, true, false);
	}

	if (to_move_right && id < T && gear_right(id) != gear_left(id + 1)) {
		rotate(id + 1, direction * -1, false, true);
	}

	gear_top[id] = (gear_top[id] - direction + 8) % 8;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> T;

	gears = vector<vector<int>>(T + 1, vector<int>(8));
	gear_top = vector<int>(T + 1, 0);

	for (int i = 1; i <= T; ++i) {
		for (int k = 0; k < 8; ++k) {
			char c;
			cin >> c;
			gears[i][k] = c - '0';
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int id, direction;
		cin >> id >> direction;

		rotate(id, direction);
	}

	int result = 0;
	for (int id = 1; id <= T; ++id) {
		result += gears[id][gear_top[id]];
	}

	cout << result;

	return 0;
}