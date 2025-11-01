#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void test_case(void) {
	string str;
	cin >> str;

	sort(str.begin(), str.end());

	do {
		cout << str << '\n';
	} while (next_permutation(str.begin(), str.end()));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		test_case();
	}

	return 0;
}