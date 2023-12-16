#include <iostream>
#include <string>

using namespace std;

int count(const int num, const int target) {
	int result = 0;
	string str_num = to_string(num);
	for (const char c : str_num) {
		if (c - '0' == target) {
			++result;
		}
	}

	return result;
}

int main(void) {
	int num, target;
	cin >> num >> target;

	int result = 0;
	for (int i = 1; i <= num; ++i) {
		result += count(i, target);
	}

	cout << result;

	return 0;
}