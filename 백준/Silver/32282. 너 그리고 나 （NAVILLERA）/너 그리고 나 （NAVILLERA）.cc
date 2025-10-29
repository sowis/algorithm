#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double x, y, c;
	cin >> x >> y >> c;

	if (x == 0 && y == 0) {
		cout << 0;
		return 0;
	}

	const double dist = sqrt(x * x + y * y);
	if (floor(dist / c) * c == dist) {
		cout << (int)floor(dist / c);
		return 0;
	}

	const int result = max(2, (int)ceil(dist / c));
	cout << result;

	return 0;
}