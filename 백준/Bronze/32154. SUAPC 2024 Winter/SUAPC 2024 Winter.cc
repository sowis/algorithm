#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<vector<char>> solved{ {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'},
		{'A', 'B', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'},
		{'A', 'B', 'C', 'F', 'G', 'H', 'L', 'M'} };

	int N;
	cin >> N;

	cout << solved[N - 1].size() << "\n";
	for (const char c : solved[N - 1]) {
		cout << c << " ";
	}

	return 0;
}