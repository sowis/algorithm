#include <iostream>
#include <string>

using namespace std;

void test_case(void) {
	string s1, s2;
	cin >> s1 >> s2;

	cout << "Distances: ";
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] <= s2[i]) {
			cout << s2[i] - s1[i] << " ";
		}
		else {
			cout << s2[i] + 26 - s1[i] << " ";
		}
	}

	cout << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}