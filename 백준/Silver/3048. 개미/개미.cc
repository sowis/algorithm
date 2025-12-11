#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct _data {
	char c;
	int direction;
} Data;

int main(void) {
	int n1, n2;
	cin >> n1 >> n2;

	vector<Data> ants;
	for (int i = 0; i < n1; ++i) {
		char n1_ant;
		cin >> n1_ant;
		ants.push_back({ n1_ant, 1 });
	}

	reverse(ants.begin(), ants.end());

	for (int i = 0; i < n2; ++i) {
		char n2_ant;
		cin >> n2_ant;
		ants.push_back({ n2_ant, -1 });
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		for (int k = 0; k < ants.size() - 1; ++k) {
			if (ants[k].direction == 1 && ants[k + 1].direction == -1) {
				swap(ants[k], ants[k + 1]);
				++k;
			}
		}
	}

	for (const Data& ant : ants) {
		cout << ant.c;
	}
	cout << "\n";

	return 0;
}