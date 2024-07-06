#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string flower;
		cin >> flower;

		const int mid = (int)flower.size() / 2;
		if (flower[mid - 1] == flower[mid]) {
			cout << "Do-it\n";
		}
		else {
			cout << "Do-it-Not\n";
		}
	}

	return 0;
}