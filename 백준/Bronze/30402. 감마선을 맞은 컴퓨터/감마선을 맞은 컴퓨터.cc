#include <iostream>

using namespace std;

int main(void) {
	for (int y = 0; y < 15; ++y) {
		for (int x = 0; x < 15; ++x) {
			char c;
			cin >> c;

			if (c == 'w') {
				cout << "chunbae\n";
				return 0;
			}
			else if (c == 'b') {
				cout << "nabi\n";
				return 0;
			}
			else if (c == 'g') {
				cout << "yeongcheol\n";
				return 0;
			}
		}
	}

	return 0;
}