#include <iostream>
#include <string>

using namespace std;

bool is_valid(const string& credit_num) {
	bool even = true;
	int credit_sum = 0;
	for (const char c : credit_num) {
		int cur = (c - '0');
		if (even) {
			cur *= 2;
		}

		credit_sum += (cur / 10) + (cur % 10);
		even = !even;
	}

	return (credit_sum % 10) == 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string credit_num;
		cin >> credit_num;

		if (is_valid(credit_num)) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}

	return 0;
}