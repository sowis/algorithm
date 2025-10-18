#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int half_sum = 0;
	vector<int> distances(N);
	for (int& dist : distances) {
		cin >> dist;
		half_sum += dist;
	}

	half_sum /= 2;

	int left = 0;
	int right = 0;
	int current_sum = 0;
	int result = 0;
	while (left < N) {
		while (current_sum + distances[right] <= half_sum) {
			current_sum += distances[right];
			right = (right + 1) % N;
		}

		result = max(result, current_sum);

		current_sum -= distances[left];
		++left;
	}

	cout << result;

	return 0;
}