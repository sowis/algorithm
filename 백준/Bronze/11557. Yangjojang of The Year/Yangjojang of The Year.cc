#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _school {
	string name;
	int drink;

	bool operator<(const _school& another) const {
		return this->drink > another.drink;
	}
} School;

void test_case(void) {
	int num;
	cin >> num;

	vector<School> schools(num);
	for (School& school : schools) {
		cin >> school.name;
		cin >> school.drink;
	}

	sort(schools.begin(), schools.end());

	cout << schools[0].name << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}