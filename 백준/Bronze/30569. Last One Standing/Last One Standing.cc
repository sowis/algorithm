#include <iostream>
#include <algorithm>

using namespace std;

double break_time(const double other_health, const double d, const double t) {
	double time = 0;
	double dmg = d;

	while (dmg < other_health) {
		time += t;
		dmg += d;
	}

	return time += 0.5;
}

int main(void) {
	double h1, d1, t1, h2, d2, t2;
	cin >> h1 >> d1 >> t1;
	cin >> h2 >> d2 >> t2;

	const double break_time_1 = break_time(h1, d2, t2);
	const double break_time_2 = break_time(h2, d1, t1);

	if (abs(break_time_1 - break_time_2) <= 0.5) {
		cout << "draw";
		return 0;
	}

	if (break_time_1 < break_time_2) {
		cout << "player two";
	}
	else {
		cout << "player one";
	}

	return 0;
}