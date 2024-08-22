#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	unordered_set<string> all;
	int result = 0;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		if (all.find(str) != all.end()) {
			continue;
		}

		string rotate = str;
		for (int k = 0; k < str.size(); ++k) {
			rotate.erase(0, 1);
			rotate += str[k];
			all.insert(rotate);
		}

		++result;
	}

	cout << result;

	return 0;
}