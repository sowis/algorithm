#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	unordered_map<string, int> board;
	for (int i = 0; i < N; ++i) {
		string name;
		int count;

		cin >> name >> count;

		board[name] += count;
	}

	for (const pair<string, int>& p : board) {
		if (p.second == 5) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}