#include <iostream>
#include <string>

using namespace std;

void test_case(void) {
	string s1, s2;
	cin >> s1 >> s2;

	int result = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) {
			++result;
		}
	}

	cout << "Hamming distance is " << result << ".\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}


	return 0;
}