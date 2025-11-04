#include <iostream>
#include <string>

using namespace std;

int get_size(const int begin, const string& str) {
	int result = 0;
	for (int i = begin; i < str.size();) {
		if (str[i] == ')') {
			break;
		}

		if (i < str.size() - 1 && str[i + 1] == '(') {
			result += (str[i] - '0') * get_size(i + 2, str);

			i += 2;
			int open_count = 1;
			while (open_count > 0) {
				if (str[i] == '(') {
					++open_count;
				}

				if (str[i] == ')') {
					--open_count;
				}

				++i;
			}

			continue;
		}

		++result;
		++i;
	}

	return result;
}

int main(void) {
	string s;
	cin >> s;

	const int result = get_size(0, s);
	cout << result;

	return 0;
}