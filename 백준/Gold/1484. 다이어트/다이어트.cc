#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long G;
	cin >> G;

	long long current = 2;
	long long remember = 1;

	bool exist = false;
	while (remember < current) {
		if (current * current == remember * remember + G) {
			cout << current << "\n";
			++current;
			exist = true;
		}
		else if (current * current > remember * remember + G ) {
			++remember;
		}
		else {
			++current;
		}
	}

	if (exist == false) {
		cout << "-1\n";
	}

	return 0;
}