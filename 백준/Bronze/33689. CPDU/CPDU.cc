#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		if (str[0] == 'C') {
			++result;
		}
	}

	cout << result;

	return 0;
}