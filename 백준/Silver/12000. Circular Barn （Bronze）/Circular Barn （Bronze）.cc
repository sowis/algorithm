#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int dist(const int N, const int door, const int target) {
	if (door <= target) {
		return target - door;
	}
	else {
		return N + target - door;
	}
}

int main(void) {
	int N;
	cin >> N;

	vector<int> cows(N);
	for (int i = 0; i < N; ++i) {
		cin >> cows[i];
	}

	int result = numeric_limits<int>::max();
	for (int door = 0; door < N; ++door) {
		int cur_sum = 0;
		for (int i = 0; i < N; ++i) {
			cur_sum += ((i - door + N) % N) * cows[i];
		}

		result = min(result, cur_sum);
	}

	cout << result;

	return 0;
}