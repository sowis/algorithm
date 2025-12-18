#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

int to_base_10(const int b, const string& str) {
	int result = 0;
	for (int i = 0; i < str.size(); ++i) {
		const int digit = (int)str.size() - i - 1;
		int num;
		if (str[i] >= 'a' && str[i] <= 'z') {
			num = 10 + str[i] - 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			num = 10 + str[i] - 'A';
		}
		else {
			num = str[i] - '0';
		}

		result += num * (int)pow(b, digit);
	}

	return result;
}

void test_case(const int scenario_number) {
	int b;
	string x_str, y_str;
	cin >> b >> x_str >> y_str;

	int x = to_base_10(b, x_str);
	const int y = to_base_10(b, y_str);

	x %= y; // 정수부는 필요없음

	unordered_map<int, int> first_appear;
	int appear_order = 1;
	while (x != 0) {
		if (first_appear.find(x) != first_appear.end()) { // 이미 나왔던 수면
			const int result = appear_order - first_appear[x];
			cout << "Scenario #" << scenario_number << ":\n";
			cout << result << "\n\n";
			return;
		}

		first_appear[x] = appear_order;

		const int remain = (x * b) % y;

		x = remain;
		++appear_order;
	}

	cout << "Scenario #" << scenario_number << ":\n";
	cout << 0 << "\n\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case(i + 1);
	}

	return 0;
}