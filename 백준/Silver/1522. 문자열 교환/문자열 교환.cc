#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	int a_count = 0;
	for (const char c : str) {
		if (c == 'a') {
			++a_count;
		}
	}

	const int N = (int)str.size();
	int left = 0;
	int right = a_count;

	for (int i = 0; i < N; ++i) {
		str += str[i];
	}

	int cur_a_count = 0;
	for (int i = 0; i < right; ++i) {
		if (str[i] == 'a') {
			++cur_a_count;
		}
	}
	
	int min_change = a_count - cur_a_count;
	while (right < 2 * N) {
		if (str[left] == 'a') {
			--cur_a_count;
		}

		++left;
		
		if (str[right] == 'a') {
			++cur_a_count;
		}

		++right;
		min_change = min(min_change, a_count - cur_a_count);
	}

	cout << min_change;

	return 0;
}