#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	int couple_count = 0;
	for (const char seat : input) {
		if (seat == 'L') {
			++couple_count;
		}
	}

	couple_count /= 2;
	--couple_count;

	if (couple_count <= 0) {
		cout << N << "\n";
	}
	else {
		cout << N - couple_count << "\n";
	}

	return 0;
}