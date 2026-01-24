#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool board[1025][1025];
int max_right[1025];

void paint(const int begin_y, const int begin_x, const int n) {
	if (n == 0) {
		board[begin_y][begin_x] = true;
		max_right[begin_y] = max(max_right[begin_y], begin_x);
		return;
	}

	paint(begin_y, begin_x, n - 1);
	paint(begin_y, begin_x + (int)pow(2, n - 1), n - 1);
	paint(begin_y + (int)pow(2, n - 1), begin_x, n - 1);
}

int main(void) {
	int N;
	cin >> N;

	paint(0, 0, N);

	for (int y = 0; y < (int)pow(2, N); ++y) {
		for (int x = 0; x < 1025; ++x) {
			cout << (board[y][x] ? "*" : " ");
			if (max_right[y] == x) {
				break;
			}
		}

		cout << "\n";
	}

	return 0;
}