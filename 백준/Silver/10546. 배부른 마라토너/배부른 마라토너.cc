#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	unordered_map<string, int> counts;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;

		++counts[name];
	}

	for (int i = 0; i < N - 1; ++i) {
		string name;
		cin >> name;

		--counts[name];
	}

	for (const pair<string, int>& p : counts) {
		if (p.second != 0) {
			cout << p.first << "\n";
			break;
		}
	}

	return 0;
}