#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A, a, B, b, P;
	cin >> A >> a >> B >> b >> P;

	if (A < B) {
		swap(A, B);
		swap(a, b);
	}

	if (A + B <= P) {
		cout << "Yes";
		return 0;
	}

	if (P < A) {
		cout << "No";
		return 0;
	}

	if (a < B) {
		cout << "No";
		return 0;
	}

	cout << "Yes";

	return 0;
}