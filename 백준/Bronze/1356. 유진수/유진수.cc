#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string number;
	cin >> number;

	for (int i = 1; i < number.size(); ++i) {
		long long a = 1;
		for (int k = 0; k < i; ++k) {
			a *= (number[k] - '0');
		}

		long long b = 1;
		for (int k = i; k < number.size(); ++k) {
			b *= (number[k] - '0');
		}

		if (a == b) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}