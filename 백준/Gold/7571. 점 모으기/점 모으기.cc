#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline long long dist(const long long x1, const long long y1, const long long x2, const long long y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<long long> x_positions(M);
	vector<long long> y_positions(M);
	vector<pair<long long, long long>> positions;

	for (int i = 0; i < M; ++i) {
		cin >> x_positions[i] >> y_positions[i];
		positions.push_back({ x_positions[i], y_positions[i] });
	}

	sort(x_positions.begin(), x_positions.end());
	sort(y_positions.begin(), y_positions.end());

	const long long target_x = x_positions[M / 2];
	const long long target_y = y_positions[M / 2];

	long long result = 0;
	for (int i = 0; i < M; ++i) {
		result += dist(target_x, target_y, positions[i].first, positions[i].second);
	}

	cout << result;

	return 0;
}