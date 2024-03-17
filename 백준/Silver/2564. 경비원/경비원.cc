#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define y first
#define x second

int width, height;

int manhattan_dist(const pair<int, int>& p1, const pair<int, int>& p2) {
	return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}

int min_dist(const pair<int, int>& p1, const pair<int, int>& p2, const vector<pair<int, int>> &box) {
	if (p1.y == 0 && p1.y == p2.y) {
		return manhattan_dist(p1, p2);
	}

	if (p1.x == 0 && p1.x == p2.x) {
		return manhattan_dist(p1, p2);
	}

	if (p1.y == height && p1.y == p2.y) {
		return manhattan_dist(p1, p2);
	}

	if (p1.x == width && p1.x == p2.x) {
		return manhattan_dist(p1, p2);
	}

	int result = 987654321;
	for (const pair<int, int>& pos : box) {
		result = min(result, manhattan_dist(p1, pos) + manhattan_dist(p2, pos));
	}

	return result;
}

int main(void) {
	scanf("%d%d", &width, &height);

	const vector<pair<int, int>> box{ {0, 0}, {0, width}, {height, 0}, {height, width} };

	int N;
	scanf("%d", &N);

	vector<pair<int, int>> pos(N + 1);
	for (pair<int, int>& p : pos) {
		int direction, distance;
		scanf("%d%d", &direction, &distance);

		int y, x;
		if (direction == 1) {
			y = 0;
			x = distance;
		}
		else if (direction == 2) {
			y = height;
			x = distance;
		}
		else if (direction == 3) {
			y = distance;
			x = 0;
		}
		else {
			y = distance;
			x = width;
		}

		p.y = y;
		p.x = x;
	}

	int result = 0;
	for (int i = 0; i < N; ++i) {
		result += min_dist(pos[i], pos[N], box);
	}

	printf("%d\n", result);

	return 0;
}