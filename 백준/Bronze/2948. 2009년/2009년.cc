#include <iostream>
#include <string>

using namespace std;

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string names[] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };

int main(void) {
	int D, M;
	cin >> D >> M;

	int day = D - 1;
	for (int i = 0; i < M - 1; ++i) {
		day += days[i];
	}

	cout << names[day % 7];

	return 0;
}