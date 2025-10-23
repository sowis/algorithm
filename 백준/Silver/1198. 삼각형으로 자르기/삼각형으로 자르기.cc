#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline double area(const pair<double, double>& p1, const pair<double, double>& p2, const pair<double, double>& p3) {
	return 0.5 * abs((p1.first* p2.second + p2.first * p3.second + p3.first * p1.second) 
		- (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first));
}

int main(void) {
	int N;
	cin >> N;

	vector<pair<double, double>> v(N);
	for (pair<double, double>& p : v) {
		cin >> p.first >> p.second;
	}

	double result = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = i + 1; k < N; ++k) {
			for (int j = k + 1; j < N; ++j) {
				result = max(result, area(v[i], v[k], v[j]));
			}
		}
	}

	cout << fixed;
	cout.precision(9);
	cout << result;

	return 0;
}