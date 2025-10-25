#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int wiggle[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, 1} }; // 아래, 오른쪽, 위, 오른쪽 꿈틀이 움직임
constexpr int DOWN = 0;

int N, M;

void wiggle_move(vector<pair<int, int>>& trace, int& y, int& x, const int end_x) {
	for (int i = 0; ; i = (i + 1) % 4) {
		const int next_y = y + wiggle[i][0];
		const int next_x = x + wiggle[i][1];
		if (next_x >= end_x) {
			break;
		}

		y = next_y;
		x = next_x;
		trace.push_back({ y, x });
	}
}

void snake_move(vector<pair<int, int>> &trace, int &y, int &x, int direction, const int end_y, const int begin_x, const int end_x) {
	while (true) {
		while (begin_x <= (x + direction) && (x + direction) < end_x) { // 가로로 끝까지 이동
			x += direction;
			trace.push_back({ y, x });
		}
		
		if (y + 1 == end_y) { // 아래로 갈 수 없으면 끝
			break;
		}

		/* 아래로 이동 */
		y += 1;
		trace.push_back({ y, x });
		/**************/

		direction *= -1; // 방향 바꾸기
	}
}

void rollback_move(vector<pair<int, int>>& trace, int& y, int& x) { // 왼쪽 한칸 이동 후 위로 쭉 올리기
	--x;
	trace.push_back({ y, x });

	while (y > 1) {
		--y;
		trace.push_back({ y, x });
	}
}

void test_case(void) {
	cin >> N >> M;

	vector<pair<int, int>> trace;
	trace.push_back({ 0, 0 });
	int direction = 1; // 오른쪽으로 갈것
	int y = 0;
	int x = 0;

	if (N % 2) { // 가로가 홀수면 꿈틀이 움직임 필요
		if (M % 2 == 0) { // 가로가 홀수고 세로가 짝수면 꿈틀이 전 오른쪽 움직임, 마지막에 롤백 움직임 필요
			++x;
			trace.push_back({ y, x });
		}

		wiggle_move(trace, y, x, M);

		/* 아래로 한칸 */
		++y;
		trace.push_back({ y, x });
		/**************/

		direction = -1; // 이후 왼쪽으로 갈것
	}

	if ((N % 2) && ((M % 2) == 0)) {
		snake_move(trace, y, x, direction, N, 1, M);
		rollback_move(trace, y, x);
	}
	else {
		snake_move(trace, y, x, direction, N, 0, M);
	}

	/* 출력 */
	cout << "1\n";
	for (const pair<int, int>& p : trace) {
		cout << "(" << p.first << "," << p.second << ")\n";
	}
	/******/
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}