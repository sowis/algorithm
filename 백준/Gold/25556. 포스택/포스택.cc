#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> tops(4, 0);
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;

		bool find = false;
		for (int k = 0; k < 4; ++k) {
			if (tops[k] < input) {
				tops[k] = input;
				find = true;
				break;
			}
		}

		if (find == false) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}