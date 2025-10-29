#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void test_case(void) {
	int N;
	cin >> N;

	unordered_map<string, int> cards;
	for (int i = 0; i < N; ++i) {
		string card;
		cin >> card;
		++cards[card];
	}

	bool cheat = false;
	for (int i = 0; i < N; ++i) {
		string card;
		cin >> card;

		if (cards[card] <= 0) {
			cheat = true;
		}
		else {
			--cards[card];
		}
	}

	if (cheat) {
		cout << "CHEATER\n";
	}
	else {
		cout << "NOT CHEATER\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}