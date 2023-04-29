#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double grade(const string& str) {
	if (str == "A+") {
		return 4.3;
	}
	else if (str == "A0") {
		return 4;
	}
	else if (str == "A-") {
		return 3.7;
	}
	else if (str == "B+") {
		return 3.3;
	}
	else if (str == "B0") {
		return 3;
	}
	else if (str == "B-") {
		return 2.7;
	}
	else if (str == "C+") {
		return 2.3;
	}
	else if (str == "C0") {
		return 2;
	}
	else if (str == "C-") {
		return 1.7;
	}
	else if (str == "D+") {
		return 1.3;
	}
	else if (str == "D0") {
		return 1;
	}
	else if (str == "D-") {
		return 0.7;
	}
	else {
		return 0;
	}
}

int main(void) {
	int N;
	cin >> N;

	double sums = 0;
	int counts = 0;

	for (int i = 0; i < N; ++i) {
		string name, grades;
		int count;

		cin >> name >> count >> grades;
		counts += count;
		sums += grade(grades) * count;
	}

	double result = (sums / counts) * 100;
	result = round(result);
	result /= 100;


	cout << fixed;
	cout.precision(2);
	cout << result << "\n";

	return 0;
}