#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string result;
	int max_count = 0;

	for (int i = 0; i < 7; ++i) {
		string name;
		int count;
		
		cin >> name;
		cin >> count;

		if (count > max_count) {
			max_count = count;
			result = name;
		}
	}

	cout << result;

	return 0;
}