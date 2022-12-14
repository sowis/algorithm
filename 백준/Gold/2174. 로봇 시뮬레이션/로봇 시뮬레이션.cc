#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int A, B, N, M;

typedef struct {
	int id;
	int y;
	int x;
	int direction;
} Robot;

int main(void) {
	cin >> A >> B;
	cin >> N >> M;

	vector<Robot> robots;
	for (int i = 0; i < N; ++i) {
		int y, x;
		char direction;

		cin >> x >> y >> direction;
		int d;

		switch (direction) {
		case 'E':
			d = 0;
			break;
		case 'S':
			d = 1;
			break;
		case 'W':
			d = 2;
			break;
		case 'N':
			d = 3;
			break;
		}

		robots.push_back({ i + 1, B - y + 1, x, d });
	}

	for (int i = 0; i < M; ++i) {
		int robot_id, repeat;
		char op;

		cin >> robot_id >> op >> repeat;
		
		Robot& robot = robots[robot_id - 1];
		for (int k = 0; k < repeat; ++k) {
			if (op == 'F') {
				const int next_y = robot.y + directions[robot.direction][0];
				const int next_x = robot.x + directions[robot.direction][1];

				if (next_y <= 0 || next_y > B || next_x <= 0 || next_x > A) {
					cout << "Robot " << robot.id << " crashes into the wall\n";
					return 0;
				}

				for (const Robot& r : robots) {
					if (r.y == next_y && r.x == next_x) {
						cout << "Robot " << robot.id << " crashes into robot " << r.id << "\n";
						return 0;
					}
				}

				robot.y = next_y;
				robot.x = next_x;
			}
			else if (op == 'L') {
				robot.direction += 3;
				robot.direction %= 4;
			}
			else if (op == 'R') {
				robot.direction += 1;
				robot.direction %= 4;
			}
		}
	}

	cout << "OK\n";

	return 0;
}