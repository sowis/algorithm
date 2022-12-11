#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int K;

bool exist(const vector<pair<int, int>> &v, const pair<int, int>& target) {
	for (const pair<int, int> &p : v) {
		if (p == target) {
			return true;
		}
	}

	return false;
}

int main(void) {
	scanf("%d", &K);

	vector<pair<int, int>> positions;
	vector<int> y_pos, x_pos;
	int y = 0, x = 0;
	for (int i = 0; i < 6; ++i) {
		int direction, distance;
		scanf("%d%d", &direction, &distance);

		--direction;
		y += directions[direction][0] * distance;
		x += directions[direction][1] * distance;
		positions.push_back({ y, x });
		y_pos.push_back(y);
		x_pos.push_back(x);
	}

	sort(positions.begin(), positions.end());
	sort(y_pos.begin(), y_pos.end());
	sort(x_pos.begin(), x_pos.end());

	pair<int, int> unexist_pos;
	if (exist(positions, { y_pos[0], x_pos[0] }) == false) {
		unexist_pos = { y_pos[0], x_pos[0] };
	}
	else if (exist(positions, { y_pos[0], x_pos[5] }) == false) {
		unexist_pos = { y_pos[0], x_pos[5] };
	}
	else if (exist(positions, { y_pos[5], x_pos[0] }) == false) {
		unexist_pos = { y_pos[5], x_pos[0] };
	}
	else {
		unexist_pos = { y_pos[5], x_pos[5] };
	}

	const int all = abs((y_pos[0] - y_pos[5]) * (x_pos[0] - x_pos[5]));
	const int remove = abs((unexist_pos.first - y_pos[2]) * (unexist_pos.second - x_pos[2]));

	printf("%d\n", (all - remove) * K);

	return 0;
}