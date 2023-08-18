#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	set<string> s;
	string input;
	int result = 0;

	for (int i = 0; i < N; ++i) {
		cin >> input;

		if (input == "ENTER") {
			result += (int)s.size();
			s.clear();
			continue;
		}

		s.insert(input);
	}

	result += (int)s.size();

	cout << result << "\n";

	return 0;
}