#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	unordered_map<char, int> counts;
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;

		++counts[c];
	}

	char target;
	cin >> target;

	cout << counts[target];


	return 0;
}