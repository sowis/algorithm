#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int str_to_min(const string& str) {
	const int hour = ((str[0] - '0') * 10 + (str[1] - '0')) % 12;
	const int min = (str[3] - '0') * 10 + (str[4] - '0');
	return hour * 60 + min;
}

int main(void) {
	string str1, str2;
	cin >> str1 >> str2;

	const int time_1 = str_to_min(str1);
	const int time_2 = str_to_min(str2);

	const int min_diff = min(abs(time_1 - time_2), 720 - abs(time_1 - time_2));
	cout << min_diff * 6;

	return 0;
}