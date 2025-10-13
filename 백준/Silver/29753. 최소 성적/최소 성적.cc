#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<string, double>> score_map;

double get_score(const string &scr) {
	for (const pair<string, double> &s : score_map) {
		if (s.first == scr) {
			return s.second;
		}
	}

	return -987654321; // error
}

int main(void) {
	score_map.push_back({ "F", 0 });
	score_map.push_back({ "D0", 100 });
	score_map.push_back({ "D+", 150 });
	score_map.push_back({ "C0", 200 });
	score_map.push_back({ "C+", 250 });
	score_map.push_back({ "B0", 300 });
	score_map.push_back({ "B+", 350 });
	score_map.push_back({ "A0", 400 });
	score_map.push_back({ "A+", 450 });

	int N;
	cin >> N;

	double target;
	cin >> target;
	target *= 100;

	int c_sum = 0;
	double c_mul_g_sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		int c;
		string g;

		cin >> c >> g;

		c_sum += c;
		c_mul_g_sum += c * get_score(g);
	}

	int current_c;
	cin >> current_c;

	c_sum += current_c;

	for (const pair<string, double>& p : score_map) {
		const double score = p.second;

		// cout << "target: " << floor(target) << "   cur: " << p.first << "  value: " << floor((c_mul_g_sum + score * current_c) / c_sum) << "\n"; // test

		if (round(target) < floor((c_mul_g_sum + score * current_c) / c_sum)) {
			cout << p.first;
			return 0;
		}
	}

	cout << "impossible";

	return 0;
}