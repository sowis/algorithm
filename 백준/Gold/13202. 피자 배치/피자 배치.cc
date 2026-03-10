#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979;

void test_case(void) {
	double a, b;
	int k;

	cin >> a >> b >> k;

	vector<double> radiuses;
	const double c = sqrt(a * a + b * b);
	const double first_radius = a * b / (a + b + c);
	radiuses.push_back(first_radius);

	double cur_radius = first_radius;
	double sin_value = 1 / sqrt(2);
	double ratio = (1 - sin_value) / (1 + sin_value);
	for (int i = 1; i < 100; ++i) {
		cur_radius *= ratio;
		radiuses.push_back(cur_radius);
	}

	cur_radius = first_radius;
	sin_value = sqrt((c - b) / (2 * c));
	ratio = (1 - sin_value) / (1 + sin_value);
	for (int i = 1; i < 100; ++i) {
		cur_radius *= ratio;
		radiuses.push_back(cur_radius);
	}

	cur_radius = first_radius;
	sin_value = sqrt((c - a) / (2 * c));
	ratio = (1 - sin_value) / (1 + sin_value);
	for (int i = 1; i < 100; ++i) {
		cur_radius *= ratio;
		radiuses.push_back(cur_radius);
	}

	sort(radiuses.begin(), radiuses.end(), greater<double>());
	cout << radiuses[k - 1] * radiuses[k - 1] * pi << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}