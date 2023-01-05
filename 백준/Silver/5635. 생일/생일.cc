#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _data {
	string name;
	int day;
	int month;
	int year;

	bool operator<(const struct _data& d) const {
		if (year != d.year) {
			return year < d.year;
		}

		if (month != d.month) {
			return month < d.month;
		}
		
		return day < d.day;
	}
} Data;

istream& operator>>(istream& is, Data &d) {
	is >> d.name >> d.day >> d.month >> d.year;
	return is;
}

int main(void) {
	int N;
	cin >> N;

	vector<Data> datas(N);
	for (Data& d : datas) {
		cin >> d;
	}

	sort(datas.begin(), datas.end());

	cout << datas[N - 1].name << "\n";
	cout << datas[0].name << "\n";

	return 0;
}