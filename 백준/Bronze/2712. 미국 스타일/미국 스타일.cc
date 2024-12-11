#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	cout << fixed;
	cout.precision(4);

	for (int i = 0; i < T; ++i) {
		double num;
		string unit;
		cin >> num >> unit;

		if (unit == "kg") {
			cout << round(num * 2.2046 * 10000) / 10000 << " lb\n";
		}
		else if (unit == "l") {
			cout << round(num * 0.2642 * 10000) / 10000 << " g\n";
		}
		else if (unit == "lb") {
			cout << round(num * 0.4536 * 10000) / 10000 << " kg\n";
		}
		else {
			cout << round(num * 3.7854 * 10000) / 10000 << " l\n";
		}
	}

	return 0;
}