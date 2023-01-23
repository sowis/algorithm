#include <iostream>
#include <string>

using namespace std;

int main(void) {
	unsigned long long N;
	while (cin >> N) {
		unsigned long long target = 1;
		int result = 1;
	
		while (target % N) {
			target *= 10;
			target += 1;
			target %= N;
			++result;
		}

		cout << result << "\n";
	}

	return 0;
}