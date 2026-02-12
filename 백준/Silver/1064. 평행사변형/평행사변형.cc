#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(const pair<double, double>& p1, const pair<double, double>& p2) {
	return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int main(void) {
	vector<pair<double, double>> v(3);
	
	for (pair<double, double>& p : v) {
		cin >> p.first >> p.second;
	}

	if (abs(v[0].first - v[1].first) < 0.00000001 && abs(v[1].first - v[2].first) < 0.00000001) {
		cout << -1;
		return 0;
	}

	if (abs(v[0].second - v[1].second) < 0.00000001 && abs(v[1].second - v[2].second) < 0.00000001) {
		cout << -1;
		return 0;
	}

	if (abs(((v[1].second - v[0].second) * (v[2].first - v[1].first)) - ((v[2].second - v[1].second) * (v[1].first - v[0].first))) < 0.00000001) {
		cout << -1;
		return 0;
	}

	vector<double> lines;
	for (int i = 0; i < 3; ++i) {
		for (int k = i + 1; k < 3; ++k) {
			lines.push_back(distance(v[i], v[k]));
		}
	}

	sort(lines.begin(), lines.end());

	const double max_circumference = 2 * (lines[1] + lines[2]);
	const double min_circumference = 2 * (lines[0] + lines[1]);
	
	cout.fixed;
	cout.precision(15);

	cout << max_circumference - min_circumference;

	return 0;
}