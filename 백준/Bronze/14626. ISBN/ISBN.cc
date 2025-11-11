#include <iostream>
#include <vector>

using namespace std;

bool isbn_check(const vector<char>& isbn) {
	int v_sum = 0;
	for (int i = 0; i < 12; ++i) {
		if (i % 2) {
			v_sum += 3 * (isbn[i] - '0');
		}
		else {
			v_sum += (isbn[i] - '0');
		}
	}

	return ((v_sum + (isbn[12] - '0')) % 10) == 0;
}

int main(void) {
	vector<char> isbn(13);
	int block_index;
	for (int i = 0; i < 13; ++i) {
		cin >> isbn[i];
		if (isbn[i] == '*') {
			block_index = i;
		}
	}

	for (char c = '0'; c <= '9'; ++c) {
		isbn[block_index] = c;
		if (isbn_check(isbn)) {
			cout << c;
			break;
		}
	}
	
	return 0;
}