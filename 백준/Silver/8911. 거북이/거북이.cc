#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

constexpr int directions[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

void test_case(void) {
	int max_y = 0;
	int max_x = 0;
	int min_y = 0;
	int min_x = 0;

	int cur_y = 0;
	int cur_x = 0;
	int d = 0;

	string operations;
	cin >> operations;

	for (const char op : operations) {
		if (op == 'F') {
			cur_y += directions[d][0];
			cur_x += directions[d][1];

			max_y = max(max_y, cur_y);
			max_x = max(max_x, cur_x);
			min_y = min(min_y, cur_y);
			min_x = min(min_x, cur_x);
		}
		else if (op == 'B') {
			cur_y -= directions[d][0];
			cur_x -= directions[d][1];

			max_y = max(max_y, cur_y);
			max_x = max(max_x, cur_x);
			min_y = min(min_y, cur_y);
			min_x = min(min_x, cur_x);
		}
		else if (op == 'L') {
			d = (d + 1) % 4;
		}
		else {
			d = (d + 3) % 4;
		}
	}

	const int result = abs(max_y - min_y) * abs(max_x - min_x);
	cout << result << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}