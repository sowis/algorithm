#include <iostream>
#include <string>

using namespace std;

string Fn(const string& num) {
	string result = num;
	for (char &c : result) {
		c = (9 - (c - '0')) + '0';
	}
	
	return result;
}

inline long long lovely(const string& num) {
	return stoll(num) * stoll(Fn(num));
}

void test_case(void) {
	string num;
	cin >> num;

	if (num[0] > '4') {
		num[0] = '4';
		for (int i = 1; i < num.size(); ++i) {
			num[i] = '9';
		}
	}

	cout << lovely(num) << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}