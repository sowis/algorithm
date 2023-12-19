#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> answer;

pair<int, int> f(const vector<string>& board, const char target) {
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			if (board[y][x] == target) {
				return { y, x };
			}
		}
	}

	return { -1, -1 };
}

int main(void) {
	answer.push_back("ABCD");
	answer.push_back("EFGH");
	answer.push_back("IJKL");
	answer.push_back("MNO.");

	int result = 0;

	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			char cur;
			cin >> cur;

			if (cur == '.') {
				continue;
			}

			const pair<int, int> target = f(answer, cur);
			const int target_y = target.first;
			const int target_x = target.second;

			const int dist = abs(target_y - y) + abs(target_x - x);
			result += dist;
		}
	}

	cout << result;

	return 0;
}