#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		if (input.size() >= 6 && input.size() <= 9) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}