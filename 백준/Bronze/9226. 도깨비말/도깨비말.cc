#include  <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	while (cin >> input) {
		if (input == "#") {
			break;
		}

		string result;
		int idx = 0;
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
				idx = i;
				break;
			}
		}

		for (int i = idx; i < input.size(); ++i) {
			result += input[i];
		}

		for (int i = 0; i < idx; ++i) {
			result += input[i];
		}

		result += "ay";

		cout << result << "\n";
	}

	return 0;
}