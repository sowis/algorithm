#include <iostream>
#include <string>

using namespace std;

bool palindrom(const string& str, const int begin) {
	for (int offset = 0; offset < str.size() - begin; ++offset) {
		const int left = begin + offset;
		const int right = (int)str.size() - 1 - offset;

		if (str[left] != str[right]) {
			return false;
		}
	}

	return true;
}

void test_case(void) {
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); ++i) {
		if (palindrom(S, i) == false) {
			continue;
		}

		string X = S;
		for (int k = i - 1; k >= 0; --k) {
			X += S[k];
		}

		cout << X << "\n";
		break;
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}