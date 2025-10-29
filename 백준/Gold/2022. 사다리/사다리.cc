#include <iostream>
#include <cmath>

using namespace std;

double get_height(const double x, const double y, const double dist) {
	const double left_wall = sqrt(x * x - dist * dist);
	const double right_wall = sqrt(y * y - dist * dist);

	return (left_wall * right_wall) / (left_wall + right_wall);
}

int main(void) {
	double x, y, c;
	cin >> x >> y >> c;

	double left = 0;
	double right = min(x, y);
	double result = 0;

	while (left + 0.001 <= right) {
		const double mid = (left + right) / 2;

		if (c <= get_height(x, y, mid)) {
			result = mid;
			left = mid;
		}
		else {
			right = mid;
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << result;

	return 0;
}