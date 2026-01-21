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
	while (N--) {
		string S;
		cin >> S;

		bool check = false;
		for (int i = 0; i < S.size() - 1; ++i) {
			if (S[i] == '0' && S[i + 1] == '1') {
				check = true;
				break;
			}
			else if (S[i] == 'O' && S[i + 1] == 'I') {
				check = true;
				break;
			}
		}

		if (check) {
			++result;
		}
	}

	cout << result;

	return 0;
}