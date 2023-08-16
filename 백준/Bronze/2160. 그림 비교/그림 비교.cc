#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Picture;

int diff(const Picture& p1, const Picture& p2) {
	int result = 0;
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 7; ++x) {
			if (p1[y][x] != p2[y][x]) {
				++result;
			}
		}
	}

	return result;
}

int main(void) {
	int N;
	cin >> N;

	vector<Picture> pictures(N, vector<vector<char>>(5, vector<char>(7)));

	for (Picture &picture : pictures) {
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 7; ++x) {
				cin >> picture[y][x];
			}
		}
	}

	int left = 0, right = 0, min_diff = 987654321;
	for (int a = 0; a < N - 1; ++a) {
		for (int b = a + 1; b < N; ++b) {
			const int d = diff(pictures[a], pictures[b]);
			if (d < min_diff) {
				left = a;
				right = b;
				min_diff = d;
			}
		}
	}

	cout << left + 1 << " " << right + 1 << "\n";

	return 0;
}