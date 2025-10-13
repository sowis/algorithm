#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int idx = 0;
	char c;
	char last = -1;

	vector<int> forelegs;
	vector<int> hindlegs;

	while (cin >> c) {
		if (last == '(' && c == '(') { // 뒷다리
			hindlegs.push_back(idx);
		}
		else if (last == ')' && c == ')') { // 앞다리
			forelegs.push_back(idx);
		}

		++idx;
		last = c;
	}

	int result = 0;
	for (const int foreleg : forelegs) {
		result += (int)(upper_bound(hindlegs.begin(), hindlegs.end(), foreleg) - hindlegs.begin());
	}

	cout << result;

	return 0;
}