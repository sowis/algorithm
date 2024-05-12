#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	string A, B;
	cin >> A >> B;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	vector<int> A_reverse(max(A.size(), B.size()) + 1, 0);
	vector<int> B_reverse(max(A.size(), B.size()) + 1, 0);
	vector<int> result(max(A.size(), B.size()) + 1, 0);

	for (int i = 0; i < A.size(); ++i) {
		A_reverse[i] = A[i] - '0';
	}

	for (int i = 0; i < B.size(); ++i) {
		B_reverse[i] = B[i] - '0';
	}

	int upper = 0;
	for (int i = 0; i < result.size(); ++i) {
		const int sum = upper + A_reverse[i] + B_reverse[i];
		upper = sum / 10;
		result[i] = sum % 10;
	}

	reverse(result.begin(), result.end());

	if (result[0] != 0) {
		cout << result[0];
	}

	for (int i = 1; i < result.size(); ++i) {
		cout << result[i];
	}

	return 0;
}