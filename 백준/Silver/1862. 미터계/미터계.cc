#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string num_s;
	cin >> num_s;

	for (char& c : num_s) {
		if (c > '4') {
			--c;
		}
	}

	int num_9 = stoi(num_s);
	int mul = 1;
	int result = 0;

	while (num_9 > 0) {
		result += (num_9 % 10) * mul;
		mul *= 9;
		num_9 /= 10;
	}

	cout << result;

	return 0;
}