#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char c;
	int comma_count = 0;
	while (cin >> c) {
		if (c == ',') {
			++comma_count;
		}
	}

	cout << comma_count + 1 << "\n";

	return 0;
}