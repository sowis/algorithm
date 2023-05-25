#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string op(const string& str, const int slice_1, const int slice_2) {
	string str_1, str_2, str_3;
	for (int i = slice_1 - 1; i >= 0; --i) {
		str_1 += str[i];
	}

	for (int i = slice_2 - 1; i >= slice_1; --i) {
		str_2 += str[i];
	}

	for (int i = (int)str.size() - 1; i >= slice_2; --i) {
		str_3 += str[i];
	}

	return str_1 + str_2 + str_3;
}

int main(void) {
	string str;
	cin >> str;

	string result = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int slice_1 = 1; slice_1 < str.size() - 1; ++slice_1) {
		for (int slice_2 = slice_1 + 1; slice_2 < str.size(); ++slice_2) {
			const string tmp = op(str, slice_1, slice_2);
			if (tmp < result) {
				result = tmp;
			}
		}
	}

	cout << result << "\n";

	return 0;
}