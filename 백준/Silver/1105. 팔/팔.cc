#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	if (a.size() != b.size()) {
		cout << 0 << "\n";
		return 0;
	}

	int result = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			break;
		}

		if (a[i] == '8' && b[i] == '8') {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}