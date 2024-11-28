#include <iostream>
#include <string>

using namespace  std;

int main(void) {
	int N;
	cin >> N;

	string old_string;
	string new_string;

	cin >> old_string;
	cin >> new_string;

	if (N % 2) {
		for (int i = 0; i < old_string.size(); ++i) {
			if (old_string[i] == new_string[i]) {
				cout << "Deletion failed";
				return 0;
			}
		}

		cout << "Deletion succeeded";
	}
	else {
		if (old_string == new_string) {
			cout << "Deletion succeeded";
		}
		else {
			cout << "Deletion failed";
		}
	}

	return 0;
}