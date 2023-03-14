#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	char dummy;
	cin >> a >> dummy >> b >> dummy >> c;

	if (a + b == c) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}