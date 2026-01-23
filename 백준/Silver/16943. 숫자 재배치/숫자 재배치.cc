#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string A, B;
	cin >> A >> B;

	if (A.size() > B.size()) {
		cout << -1;
		return 0;
	}

	sort(A.begin(), A.end());

	string result = "0";
	while (stoi(A) < stoi(B)) {
		result = A;
		if (next_permutation(A.begin(), A.end()) == false) {
			break;
		}
	}

	if (result[0] == '0') {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}