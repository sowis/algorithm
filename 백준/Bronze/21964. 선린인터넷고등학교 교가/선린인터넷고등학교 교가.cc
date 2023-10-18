#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	for (int i = N - 5; i < N; ++i) {
		cout << input[i];
	}

	return 0;
}