#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int type_count(const vector<int>& char_count) {
	int result = 0;
	for (const int count : char_count) {
		if (count > 0) {
			++result;
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> char_count(27, 0);
	int left = 0;
	int right = 0;
	int result = 0;
	while (right < str.size()) {
		++char_count[str[right] - 'a'];
		++right;

		while (type_count(char_count) > N) {
			--char_count[str[left] - 'a'];
			++left;
		}

		result = max(result, right - left);
	}

	cout << result;

	return 0;
}