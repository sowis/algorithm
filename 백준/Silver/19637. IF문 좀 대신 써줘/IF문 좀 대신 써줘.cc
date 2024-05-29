#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, M;
	cin >> N >> M;

	vector<int> uppers;
	vector<string> names;
	for (int i = 0; i < N; ++i) {
		string name;
		int upper;

		cin >> name >> upper;

		uppers.push_back(upper);
		names.push_back(name);
	}

	for (int i = 0; i < M; ++i) {
		int power;
		cin >> power;

		const int idx = int(lower_bound(uppers.begin(), uppers.end(), power) - uppers.begin());
		cout << names[idx] << "\n";
	}

	return 0;
}