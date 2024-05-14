#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	for (int begin = 0; begin < input.size(); ++begin) {
		bool ok = true;
		int left = begin;
		int right = (int)input.size() - 1;
		while (left < right) {
			if (input[left] != input[right]) {
				ok = false;
				break;
			}

			++left;
			--right;
		}

		if (ok) {
			cout << input.size() + begin << "\n";
			break;
		}
	}

	return 0;
}