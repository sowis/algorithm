#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool anagram(const string& a, const string& b) {
	vector<int> a_count(27, 0), b_count(27, 0);

	for (const char c : a) {
		++a_count[c - 'a'];
	}

	for (const char c : b) {
		++b_count[c - 'a'];
	}

	for (int i = 0; i < 27; ++i) {
		if (a_count[i] != b_count[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		string a, b;
		cin >> a >> b;

		if (anagram(a, b)) {
			cout << a << " & " << b << " are anagrams.\n";
		}
		else {
			cout << a << " & " << b << " are NOT anagrams.\n";
		}
	}

	return 0;
}