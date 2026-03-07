#include <iostream>

using namespace std;

int main(void) {
	double A, w, v;
	cin >> A >> w >> v;

	if (w / v >= A) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}