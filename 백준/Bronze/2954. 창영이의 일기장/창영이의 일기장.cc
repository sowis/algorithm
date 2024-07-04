#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	getline(cin, input);

	string result;
	for (int i = 0; i < input.size(); ++i) {
		result += input[i];
		
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
			i += 2;
		}
	}

	cout << result << "\n";

	return 0;
}