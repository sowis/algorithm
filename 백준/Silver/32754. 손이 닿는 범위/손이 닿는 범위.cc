#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	double R;
	cin >> N >> R;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		double x_sum = 0, y_sum = 0;
		double x, y;
		for (int k = 0; k < 4; ++k) {
			cin >> x >> y;
			x_sum += x;
			y_sum += y;
		}

		const double mid_x = x_sum / 4;
		const double mid_y = y_sum / 4;
		const double mid_dist = sqrt(mid_x * mid_x + mid_y * mid_y);
		const double min_dist = mid_dist - sqrt(pow(abs(mid_x - x), 2) + pow(abs(mid_y - y), 2));

		if (min_dist <= R) {
			++result;
		}
	}

	cout << result;

	return 0;
}