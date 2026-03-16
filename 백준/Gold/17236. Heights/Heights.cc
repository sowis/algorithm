#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double h1, h2, h3;
	cin >> h1 >> h2 >> h3;

	const double x = 1 / h1;
	const double y = 1 / h2;
	const double z = 1 / h3;

	const double result = 1 / sqrt((x + y + z) * (-x + y + z) * (x - y + z) * (x + y - z));

	cout << fixed;
	cout.precision(7);
	cout << result;

	return 0;
}