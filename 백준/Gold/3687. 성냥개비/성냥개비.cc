#include <iostream>
#include <string>

using namespace std;

string max_num(int num) {
	string result;
	if (num % 2) {
		result += '7';
		num -= 3;
	}

	while (num > 0) {
		result += '1';
		num -= 2;
	}

	return result;
}

string min_num(int num) {
	string result;
	int digit = (num - 1) / 7 + 1;
	while (digit > 0) {
		const int min_remove = num - ((digit - 1) * 7);
		int remove = 0;
		if (digit == 1) {
			switch (num) {
			case 2:
				result += '1';
				break;
			case 3:
				result += '7';
				break;
			case 4:
				result += '4';
				break;
			case 5:
				result += '2';
				break;
			case 6:
				if (result.empty()) {
					result += '6';
				}
				else {
					result += '0';
				}
				break;
			default:
				result += '8';
				break;
			}
		}
		else if (result.empty()) {
			if (min_remove <= 2) {
				remove = 2;
				result += '1';
			}
			else if (min_remove <= 5) {
				remove = 5;
				result += '2';
			}
			else if (min_remove <= 6) {
				remove = 6;
				result += '6';
			}
			else {
				remove = 7;
				result += '8';
			}
		}
		else {
			if (min_remove <= 6) {
				remove = 6;
				result += '0';
			}
			else {
				remove = 7;
				result += '8';
			}
		}

		--digit;
		num -= remove;
	}

	return result;
}

void test_case() {
	int N;
	cin >> N;

	const string min_str = min_num(N);
	const string max_str = max_num(N);

	cout << min_str << " " << max_str << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}