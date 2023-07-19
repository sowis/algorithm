#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		char a, b;
		cin >> a >> b;

		int num;
		cin >> num;

		if (num <= 90) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}