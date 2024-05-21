#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	char game;
	cin >> game;

	unordered_set<string> persons;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;

		persons.insert(name);
	}

	int need;
	if (game == 'Y') {
		need = 2;
	}
	else if (game == 'F') {
		need = 3;
	}
	else {
		need = 4;
	}

	cout << persons.size() / (need - 1);

	return 0;
}