#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> positions(N);
	for (int& pos : positions) {
		cin >> pos;
	}

	int T;
	cin >> T;

	double near = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = i + 1; k < N; ++k) {
			if (abs(positions[i] - positions[k]) <= T * 2) {
				near += 1;
			}
		}
	}

	cout << near / 4;

	return 0;
}