#include <iostream>
#include <string>

using namespace std;

void test_case(void) {
	int p;
	cin >> p;

	int max_price = 0;
	string max_name;

	for (int i = 0; i < p; ++i) {
		int price;
		string name;

		cin >> price >> name;

		if (price > max_price) {
			max_price = price;
			max_name = name;
		}
	}

	cout << max_name << "\n";
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		test_case();
	}

	return 0;
}