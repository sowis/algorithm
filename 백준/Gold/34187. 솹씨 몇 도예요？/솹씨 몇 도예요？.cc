#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int left = 0;
	int right = 2025;

	while (true) {
		const int mid = (left + right) / 2;
		cout << "? " << mid << "\n";
		cout << flush;

		string input;
		cin >> input;

		if (input == "SUAPC!") {
			cout << "! " << mid << "\n";
			cout << flush;
			break;
		}
		else if (input == "Cold") {
			left = (mid + (mid + 1)) / 2;
			right = (mid + right) / 2;
		}
		else {
			left = (left + (mid - 1)) / 2;
			right = ((mid - 1) + mid) / 2;
		}
	}

	return 0;
}