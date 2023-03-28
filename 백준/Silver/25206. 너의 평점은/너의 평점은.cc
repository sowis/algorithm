#include <iostream>
#include <string>

using namespace std;

int main(void) {
	double grade_sums = 0;
	double counts = 0;

	for (int i = 0; i < 20; ++i) {
		string name, grade;
		double score;

		cin >> name >> score >> grade;
		if (grade == "P") {
			continue;
		}

		if (grade == "A+") {
			grade_sums += 4.5 * score;
		}
		else if (grade == "A0") {
			grade_sums += 4 * score;
		}
		else if (grade == "B+") {
			grade_sums += 3.5 * score;
		}
		else if (grade == "B0") {
			grade_sums += 3 * score;
		}
		else if (grade == "C+") {
			grade_sums += 2.5 * score;
		}
		else if (grade == "C0") {
			grade_sums += 2 * score;
		}
		else if (grade == "D+") {
			grade_sums += 1.5 * score;
		}
		else if (grade == "D0") {
			grade_sums += 1 * score;
		}

		counts += score;
	}

	if (counts == 0) {
		cout << "0\n";
		return 0;
	}

	cout << grade_sums / counts << "\n";

	return 0;
}