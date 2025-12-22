#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string S, P;
	cin >> S >> P;

	int result = 0;
	int to_build = 0;
	while (to_build < P.size()) {
		int max_same_len = 0;
		for (int begin = 0; begin < S.size(); ++begin) {
			for (int offset = 0; begin + offset < S.size() && to_build + offset < P.size(); ++offset) {
				if (S[begin + offset] != P[to_build + offset]) {
					break;
				}

				max_same_len = max(max_same_len, offset + 1);
			}
		}

		++result;
		to_build += max_same_len;
	}

	cout << result;

	return 0;
}